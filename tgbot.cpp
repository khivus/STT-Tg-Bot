// STT_Tg_Bot v0.0.3 Khivus 2022
//
// for compilation and start:
// g++ tgbot.cpp -o telegram_bot --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread -lcurl && ./telegram_bot
// 

#include "token.h" // including private token
// #include "google/cloud/speech/speech_client.h"
// #include "google/cloud/project.h"
// #include "langs/eng.h"
// #include "langs/rus.h"

#include <stdio.h>
#include <tgbot/tgbot.h>
#include <string>
#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class langmanager {
    public:
        const string en = "Anime)";
        const string ru = "No anime(";
        string lang;
        string bruh;

        void update() {
            if (lang == "ru-Ru") {
                bruh = ru;
            }
            else if (lang == "en-US"){
                bruh = en;
            }
        }
};

// string lang_update[] (string lang) {
//     string engLang[] = { 
//         "Hello!\nFor usage reply to me voice message with used command /convert !",
//         "Hiiiii"
//     };
//     if (lang == "ru-Ru") {
//         string mlang[] = rusLang;
//     }
//     else if (lang == "en-US"){
//         string mlang[] = engLang;
//     }
//     return mlang;
// }

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) { // Func for download file with curl
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

void update_json(string uri, string lang) {
    std::ifstream input_file("sync-request.json");
    json data = json::parse(input_file);
    data["config"]["languageCode"] = lang;
    data["audio"]["uri"] = uri;
    input_file.close();

    std::ofstream output_file;
    output_file.open("sync-request.json", std::fstream::out | std::fstream::trunc);
    output_file << data.dump() << std::endl;
    output_file.close();
}

void send_voice(string url) {
    CURL *curl;
    CURLcode res;

    struct curl_httppost *post = NULL;
    struct curl_httppost *last = NULL;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    curl_formadd(
        &post, &last,
        CURLFORM_FILE, "sync-request.json",
        CURLFORM_END
    );

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

void get_voice(string url) { // Func for get voice file
    CURL *curl;
    CURLcode res;
    FILE *audiofile;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    audiofile = fopen("voice.flac", "wb"); // (re)writing to "voice.flac" file
    if(audiofile) {
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, audiofile);
        curl_easy_perform(curl);
        fclose(audiofile);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

int main() {
    TgBot::Bot bot(token);

    // string lang = "en-US";
    // string mlang[] = lang_update(lang);

    // langmanager LM;
    // LM.lang = "en-US";
    // LM.update();

    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) { // If command /start
        bot.getApi().sendMessage(message->chat->id, "LM.bruh");
    });

    bot.getEvents().onCommand("convert", [&bot](TgBot::Message::Ptr message) { // If command /getreply. This is test name
        if (message->replyToMessage != NULL && message->replyToMessage->voice != NULL) {
            printf("Bot got replied voice message.\n" // Output to console voice msg data
                    "Voice data is: [ %s, %s, %i, %s, %li ]\n", 
                    message->replyToMessage->voice->fileId.c_str(), 
                    message->replyToMessage->voice->fileUniqueId.c_str(), 
                    message->replyToMessage->voice->duration, 
                    message->replyToMessage->voice->mimeType.c_str(), 
                    message->replyToMessage->voice->fileSize);
            auto file_path = bot.getApi().getFile(message->replyToMessage->voice->fileId); // Getting file path
            string file_url = "https://api.telegram.org/file/bot" + token + "/" + file_path->filePath; // Generating link to the voice msg file
            cout << file_url << "\n"; // Output the link
            get_voice(file_url); // Downloading file
            string text; // There are will be Speech-to-Text recognition
            bot.getApi().sendMessage(message->chat->id, "Placeholder", false, message->replyToMessage->messageId); // Outputting recognized text.
        }
        else {
            bot.getApi().sendMessage(message->chat->id, "Reply to the voice message and use this command again."); // If no replyed message and message isn't a voice message
        }
    });

    bot.getEvents().onCommand("language", [&bot](TgBot::Message::Ptr message) { // If command /start
        // string lang = LM.lang;
        string lang = "en-US";
        string msg;
        if (lang == "ru-Ru") {
            msg = "Выберите предпочетаемый язык.";
        }
        else {
            msg = "Select preferred language.";
        }
        bot.getApi().sendMessage(message->chat->id, msg);
    });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        if (StringTools::startsWith(message->text, "/")) 
            cout << "User used command: " << message->text.c_str() << endl;
        else
            cout << "User wrote: " << message->text.c_str() << endl;
    });

    try {
        printf("Logged on with username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            //printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    
    return 0;
}