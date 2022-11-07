// Copyright 2016 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "parse_arguments.h"
#include <google/cloud/speech/speech_client.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

namespace speech = ::google::cloud::speech;

auto constexpr kUsage = R"""(Usage:
  transcribe [--bitrate N] audio.(raw|ulaw|flac|amr|awb|oga|ogg)
)""";

int main(int argc, char** argv) try {
  // [START speech_sync_recognize]
  // [START speech_sync_recognize_gcs]
  // Create a Speech client with the default configuration
  // std::cout << "1. Connection...\n";
  auto client = speech::SpeechClient(speech::MakeSpeechConnection());
  // Parse command line arguments.
  // std::cout << "2. Parsing args...\n";
  auto const args = ParseArguments(argc, argv);
  speech::v1::RecognizeRequest request;
  *request.mutable_config() = args.config;
  // [END speech_sync_recognize_gcs]
  // [END speech_sync_recognize]
  if (args.path.rfind("gs://", 0) == 0) {
    // std::cout << "3. if args.path.rfind(\"gs://\", 0) == 0...\n";
    // [START speech_sync_recognize_gcs]
    // Pass the Google Cloud Storage URI to the request.
    request.mutable_audio()->set_uri(args.path);
    // [END speech_sync_recognize_gcs]
  } else {
    // std::cout << "3. else...\n";
    // [START speech_sync_recognize]
    // Load the audio file from disk into the request.
    auto content =
        std::string{std::istreambuf_iterator<char>(
                        std::ifstream(args.path, std::ios::binary).rdbuf()),
                    {}};
    request.mutable_audio()->mutable_content()->assign(std::move(content));
    // [END speech_sync_recognize]
  }
  // [START speech_sync_recognize]
  // [START speech_sync_recognize_gcs]
  // Send audio content using Recognize().
  // std::cout << "4. Waiting response from server...\n";
  auto response = client.Recognize(request);
  if (!response) throw std::move(response).status();
  // Dump the transcript of all the results.
  // std::cout << "5. Got response...\n";
  for (auto const& result : response->results()) {
    // std::cout << "Analized text: ";
    for (auto const& alternative : result.alternatives()) {
      // std::cout << "6. Reading...\n";
      std::cout << alternative.transcript() << std::endl;
    }
  }
  // [END speech_sync_recognize_gcs]
  // [END speech_sync_recognize]
  return 0;
} catch (google::cloud::Status const& s) {
  std::cerr << "Recognize failed with: " << s << "\n";
  return 1;
} catch (std::exception const& ex) {
  std::cerr << "Standard C++ exception thrown: " << ex.what() << "\n"
            << kUsage << "\n";
  return 1;
}
