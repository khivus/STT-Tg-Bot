// tgbot v0.0.1 Khivus
//
// for compilation and start:
// g++ tgbot.cpp -o telegram_bot --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread -lcurl && ./telegram_bot
//

#include "token.h"

#include <stdio.h>
#include <tgbot/tgbot.h>
#include <string>
#include <iostream>
#include <curl/curl.h>

using namespace std;

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

void get_response(string url) {
    CURL *curl;
    CURLcode res;
    FILE *audiofile;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    audiofile = fopen("voice.ogg", "wb");
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
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });

    bot.getEvents().onCommand("getreply", [&bot](TgBot::Message::Ptr message) {
        if (message->replyToMessage != NULL) {
            if (message->replyToMessage->voice != NULL) {
                printf("Bot got replied voice message.\n"
                        "Voice data is: [ %s, %s, %i, %s, %li ]\n", 
                        message->replyToMessage->voice->fileId.c_str(), 
                        message->replyToMessage->voice->fileUniqueId.c_str(), 
                        message->replyToMessage->voice->duration, 
                        message->replyToMessage->voice->mimeType.c_str(), 
                        message->replyToMessage->voice->fileSize);
                auto file_path = bot.getApi().getFile(message->replyToMessage->voice->fileId);
                string file_url = "https://api.telegram.org/file/bot" + token + "/" + file_path->filePath;

                cout << file_url << "\n";

                get_response(file_url);

                //string text;
                //bot.getApi().sendMessage(message->chat->id, text, false, message->replyToMessage->messageId);
            }
        }
        else {
            bot.getApi().sendMessage(message->chat->id, "Reply to the message and use this command again.");
        }
    });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote: %s\n", message->text.c_str());
        // if (StringTools::startsWith(message->text, "/start")) {
        //     return;
        // }
        // bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
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