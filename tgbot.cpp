// STT_Tg_Bot v1.1 Khivus 2022
//
// For credentials:
// export GOOGLE_APPLICATION_CREDENTIALS=credentials-key.json
//
// For compilation and start:
// g++ tgbot.cpp -o telegram_bot --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread -lcurl -lsqlite3 && clear && ./telegram_bot
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
#include <vector>
#include <sqlite3.h>
#include <nlohmann/json.hpp>

using namespace std;
using namespace TgBot;
using json = nlohmann::json;

long int admin_chat_id = 897276284;
string admin = "khivus";
string deflang = "eng";
string chatlang;
bool adding_trusted = false;
bool deleting_trusted = false;
bool callforward = false;
int msgid;

static int callback_msg(void *data, int argc, char **argv, char **azColName) {
   chatlang = argv[1];
   if (argv[0] || argv[1])
        callforward = true;
   return 0;
}

static int callback(void *data, int argc, char **argv, char **azColName) {
   for(int i = 0; i < argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   return 0;
}

bool is_chat_in_db(sqlite3* DB, Message::Ptr message) {
    int exit = 0;
    exit = sqlite3_exec(DB, ("SELECT * FROM chats WHERE chat_id = " + to_string(message->chat->id)).c_str(), callback_msg, 0, NULL);
    if (exit != SQLITE_OK) 
        cerr << "Error checking db!\n";
    
    if (callforward) {
        callforward = false;
        return false;
    }
    else 
        return true;
}

bool is_trusted(string username) {
    ifstream users;
    users.open("trusted-users.txt", ifstream::in);
    string user;
    while (!users.eof()) {
        users >> user;
        if (username == user) {
            users.close();
            return true;
        }
    }
    users.close();
    return false;
}

string get_msg(string mode, sqlite3* DB, Message::Ptr message) {
    ifstream file;
    json data;
    string msg;

    sqlite3_exec(DB, ("SELECT * FROM chats WHERE chat_id = " + to_string(message->chat->id)).c_str(), callback_msg, 0, NULL);

    if (chatlang == "rus")
        file.open("languages/rus.json", ifstream::in);
    else
        file.open("languages/eng.json", ifstream::in);
    
    data = json::parse(file);
    msg = data[mode].get<string>();

    file.close();

    return msg;
}

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) { // Func for download file with curl
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

void get_voice(string url) { // Func for get voice file
    CURL *curl;
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

int main() {
    Bot bot(token);

    int exit = 0;
    sqlite3* DB;
    exit = sqlite3_open("languages/langhandler.db", &DB);
    if (!exit)
        cout << "Database opened succsessfully.\n";
    else
        cerr << "Error opening database!\n";

    Message::Ptr langmessage;
    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> row0;
    InlineKeyboardButton::Ptr rusButton(new InlineKeyboardButton);
    rusButton->text = "🇷🇺 Русский";
    rusButton->callbackData = "rus";
    InlineKeyboardButton::Ptr engButton(new InlineKeyboardButton);
    engButton->text = "🇬🇧 English";
    engButton->callbackData = "eng";
    row0.push_back(engButton);
    row0.push_back(rusButton);
    keyboard->inlineKeyboard.push_back(row0);
    //
    // -------------------- On Command --------------------
    //
    bot.getEvents().onCommand("start", [&bot, &DB](Message::Ptr message) { // Command /start
        string resp; 
        if (message->from->username == admin && message->chat->id == admin_chat_id) 
            resp = get_msg("admin_start", DB, message);
        else 
            resp = get_msg("start", DB, message);
        bot.getApi().sendMessage(message->chat->id, resp);
    });

    bot.getEvents().onCommand("convert", [&bot, &DB](Message::Ptr message) { // Command /convert
        if (is_trusted(message->from->username)) {
            if (message->replyToMessage != NULL && message->replyToMessage->voice != NULL) {
                printf("\n---------- Convert used ----------\n"
                        "Bot got replied voice message.\n"
                        "Voice data is: [ %s, %s, %i, %s, %li ]\n", 
                        message->replyToMessage->voice->fileId.c_str(), 
                        message->replyToMessage->voice->fileUniqueId.c_str(), 
                        message->replyToMessage->voice->duration, 
                        message->replyToMessage->voice->mimeType.c_str(), 
                        message->replyToMessage->voice->fileSize);
                File::Ptr file_path = bot.getApi().getFile(message->replyToMessage->voice->fileId); // Getting file path
                string file_url = "https://api.telegram.org/file/bot" + token + "/" + file_path->filePath; // Generating link to the voice msg file
                cout << file_url << "\n"; // Output the link
                get_voice(file_url); // Downloading file

                bool is_recognized = true;
                string text;
                array<char, 128> buffer;
                FILE* pipe;

                sqlite3_exec(DB, ("SELECT * FROM chats WHERE chat_id = " + to_string(message->chat->id)).c_str(), callback_msg, 0, NULL);

                if (chatlang == "rus")
                    pipe = popen("Google-speech-api/.build/transcribe --bitrate 48000 --language-code ru audio.oga", "r");
                else
                    pipe = popen("Google-speech-api/.build/transcribe --bitrate 48000 audio.oga", "r");

                if (!pipe) {
                    is_recognized = false;
                    text = get_msg("reco_fail", DB, message);
                }
                else {
                    cout << "Listening...\n";
                    while (fgets(buffer.data(), 128, pipe) != NULL) {
                        text += buffer.data();
                    }
                }
                int returnCode = pclose(pipe);
                if (text == "") {
                    is_recognized = false;
                    cout << "Text is empty.\n";
                    text = get_msg("reco_fail", DB, message);
                }
                if (text == "банка\n")
                    bot.getApi().sendMessage(message->chat->id, "Пошел нахуй!", false, message->replyToMessage->messageId);
                if (is_recognized)
                    text = get_msg("reco", DB, message) + text;
                cout << text;
                cout << "Return code: " << returnCode << endl;
                
                bot.getApi().sendMessage(message->chat->id, text, false, message->replyToMessage->messageId); // Outputting recognized text.
            }
            else {
                bot.getApi().sendMessage(message->chat->id, get_msg("reco_fail_reply", DB, message)); // If no replyed message and message isn't a voice message
            }
        }
        else {
            bot.getApi().sendMessage(message->chat->id, get_msg("not_trusted", DB, message));
        }
    });

    bot.getEvents().onCommand("language", [&bot, &keyboard, &DB, &langmessage](Message::Ptr message) { // Command /language
        langmessage = bot.getApi().sendMessage(message->chat->id, get_msg("language", DB, message), false, 0, keyboard);
    });

    bot.getEvents().onCommand("about", [&bot, &DB](Message::Ptr message) { // Command /about
        bot.getApi().sendMessage(message->chat->id, get_msg("about", DB, message));
    });

    bot.getEvents().onCommand("addtrusted", [&bot, &DB](Message::Ptr message) { // Admin command /addtrusted
        if (message->from->username == admin) {
            Message::Ptr bot_msg = bot.getApi().sendMessage(message->chat->id, get_msg("addtrusted", DB, message));
            adding_trusted = true;
            cout << "Waiting response for add trusted user...\n";
            msgid = bot_msg->messageId;
        }
    });

    bot.getEvents().onCommand("deltrusted", [&bot, &DB](Message::Ptr message) { // Admin command /deltrusted
        if (message->from->username == admin) {
            Message::Ptr bot_msg = bot.getApi().sendMessage(message->chat->id, get_msg("deltrusted", DB, message));
            deleting_trusted = true;
            cout << "Waiting response for delete trusted user...\n";
            msgid = bot_msg->messageId;
        }
    });

    bot.getEvents().onCommand("showtrusted", [&bot, &DB](Message::Ptr message) { // Admin command /showtrusted
        if (message->from->username == admin) {
            string user, users = "";
            ifstream file;
            file.open("trusted-users.txt", ifstream::in);
            while (!file.eof()) {
                file >> user;
                cout << user << " ";
                users = users + "\n@" + user;
            }
            cout << endl;
            bot.getApi().sendMessage(message->chat->id, get_msg("showtrusted", DB, message) + users);
        }
    });
    //
    // -------------------- On Callback Query --------------------
    //
    bot.getEvents().onCallbackQuery([&bot, &keyboard, &DB, &langmessage](CallbackQuery::Ptr query) { // When pressed button after using command /language
        cout << endl << query->from->username << " pressed button " << query->data << endl;
        sqlite3_exec(DB, (string("UPDATE chats set language = '") + query->data + "' where chat_id = " + to_string(query->message->chat->id)).c_str(), nullptr, 0, nullptr);
        cout << "Changed language in chat " << query->message->chat->id << " to " << query->data << endl;
        bot.getApi().editMessageText(get_msg("selected_language", DB, langmessage), langmessage->chat->id, langmessage->messageId);
    });
    //
    // -------------------- On Any Message --------------------
    //
    bot.getEvents().onAnyMessage([&bot, &DB](Message::Ptr message) { 

        cout << "\n---------- New message ----------\n";
        sqlite3_exec(DB, ("SELECT * FROM chats WHERE chat_id = " + to_string(message->chat->id)).c_str(), callback, 0, nullptr);
        if(is_chat_in_db(DB, message)) {
            cout << "Adding " << message->chat->id << " with default English language to the db...\n";
            sqlite3_exec(DB, (string("INSERT INTO chats VALUES(") + to_string(message->chat->id) + ", '" + deflang + "')").c_str(), nullptr, 0, nullptr);
            bot.getApi().sendMessage(message->chat->id, get_msg("lang_prefer", DB, message));
        }
        if (StringTools::startsWith(message->text, "/")) 
            cout << message->from->username << " used command: " << message->text.c_str() << endl;
        else if (message->text == "" && message->voice) 
            cout << message->from->username << " send a voice message." << endl;
        else
            cout << message->from->username << " wrote: " << message->text.c_str() << endl;
        
        if (message->replyToMessage && message->from->username == admin) {
            if (adding_trusted && msgid == message->replyToMessage->messageId) {
                adding_trusted = false;
                string msg = message->text;

                if (StringTools::startsWith(msg, "@")) {
                    msg.erase(0,1);
                }
                cout << "Adding @" << msg << "...\n";

                ofstream users;
                users.open("trusted-users.txt", ofstream::out | ofstream::app);
                users << endl << msg;
                users.close();

                bot.getApi().sendMessage(message->chat->id, get_msg("added_trusted", DB, message) + msg);
            }
            else if (deleting_trusted && msgid == message->replyToMessage->messageId) {
                deleting_trusted = false;
                string msg = message->text;
                string user;
                vector<string> susers;
                int i = 0;

                if (StringTools::startsWith(msg, "@")) {
                    msg.erase(0,1);
                }
                cout << "Deleting @" << msg << "...\n";

                ifstream users;
                users.open("trusted-users.txt", ifstream::in);
                while(!users.eof()) {
                    users >> user;
                    if (user != msg)
                        susers.push_back(user);
                }
                users.close();

                ofstream usersus;
                usersus.open("trusted-users.txt", ofstream::out | ofstream::trunc);
                while (!susers.empty()){
                    user = susers.back();
                    susers.pop_back();
                    if (i == 0) 
                        usersus << user;
                    else
                        usersus << endl << user;
                    i++;
                }
                usersus.close();

                bot.getApi().sendMessage(message->chat->id, get_msg("deleted_trusted", DB, message) + msg);
            }
            else if (msgid != message->replyToMessage->messageId && (adding_trusted || deleting_trusted)) {
                bot.getApi().sendMessage(message->chat->id, get_msg("trusted_reply_fail", DB, message));
            }
        }
        else if ((adding_trusted || deleting_trusted) && message->from->username == admin && !message->replyToMessage) {
            bot.getApi().sendMessage(message->chat->id, get_msg("trusted_fail", DB, message));
        }
    });

    try {
        printf("Logged on with username: %s\n", bot.getApi().getMe()->username.c_str());
        TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    } catch (TgException& e) {
        printf("error: %s\n", e.what());
    }

    sqlite3_close(DB);
    return 0;
}