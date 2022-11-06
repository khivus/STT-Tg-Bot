// STT_Tg_Bot v0.1.2 Khivus 2022
//
// for compilation and start:
// g++ tgbot.cpp -o telegram_bot --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread -lcurl && ./telegram_bot
// 

#include "token.h" // including private token

#include <aio.h>
#include <stdio.h>
#include <tgbot/tgbot.h>
#include <string>
#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <iterator>
#include <array>

using namespace std;

string get_msg(string deflang, int num) {
    ifstream file;
    if (deflang == "eng") {
        file.open("eng.lf", ifstream::in);
    }
    else if (deflang == "rus") {
        file.open("rus.lf", ifstream::in);
    }

    string msg;
    for (int i = 0; i < num + 1; i++) {
        getline(file, msg);
    }
    return msg;
}

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) { // Func for download file with curl
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

void get_voice(string url) { // Func for get voice file
    CURL *curl;
    CURLcode res;
    FILE *audiofile;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    audiofile = fopen("audio.oga", "wb"); // (re)writing to "audio.oga" file
    if(audiofile) {
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, audiofile);
        curl_easy_perform(curl);
        fclose(audiofile);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

string deflang = "eng";
string adminid = "khivus";

int main() {
    TgBot::Bot bot(token);

    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) { // If command /start
        string resp = get_msg(deflang, 0);
        bot.getApi().sendMessage(message->chat->id, resp);
    });

    bot.getEvents().onCommand("convert", [&bot](TgBot::Message::Ptr message) { // Main func for bot "/convert"
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

            cout << "Opening reading pipe\n";
            string text;
            array<char, 128> buffer;
            FILE* pipe;
            if (deflang == "rus")
                pipe = popen("../exmp/cpp-samples/speech/api/.build/transcribe --bitrate 48000 --language-code ru audio.oga", "r");
            else
                pipe = popen("../exmp/cpp-samples/speech/api/.build/transcribe --bitrate 48000 audio.oga", "r");

            if (!pipe) {
                text = "Can't detect voice.";
            }
            else {
                cout << "Reading...\n";
                while (fgets(buffer.data(), 128, pipe) != NULL) {
                    text += buffer.data();
                }
                cout << endl;
            }
            auto returnCode = pclose(pipe);
            if (text == "") {
                text = "placeholder";
                cout << "Text is empty.\n";
            }
            cout << text << "\n";
            cout << returnCode << endl;
            
            bot.getApi().sendMessage(message->chat->id, ("Recognized text: " + text).c_str(), false, message->replyToMessage->messageId); // Outputting recognized text.
        }
        else {
            bot.getApi().sendMessage(message->chat->id, "This command is used with reply to the voice message."); // If no replyed message and message isn't a voice message
        }
    });

    bot.getEvents().onCommand("language", [&bot](TgBot::Message::Ptr message) { // If command /start
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
        if (StringTools::startsWith(message->text, "/reboot") && message->from->username == adminid) { // very funny thing. If you use it, bot will go to infinite reboot...
            cout << "Rebooting...\n";
            bot.getApi().sendMessage(message->chat->id, "Rebooting...");
            system("python3 reboot.py");
            return 0;
        }
        if (StringTools::startsWith(message->text, "/")) 
            cout << message->from->username << " used command: " << message->text.c_str() << endl;
        
        else
            cout << message->from << " wrote: " << message->text.c_str() << endl;
    });

    try {
        printf("Logged on with username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    
    return 0;
}