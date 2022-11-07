// STT_Tg_Bot v0.14 Khivus 2022
//
// For credentials:
// export GOOGLE_APPLICATION_CREDENTIALS=credentials-key.json
//
// For compilation and start:
// g++ tgbot.cpp -o telegram_bot --std=c++14 -I/usr/local/include -lTgBot -lboost_system -lssl -lcrypto -lpthread -lcurl -lsqlite3 && ./telegram_bot
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

using namespace std;

string admin = "khivus";
string deflang = "eng";
bool adding_trusted = false;
bool deleting_trusted = false;
int msgid;
string callforward = "";

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
      callforward = callforward;
   }
   printf("\n");
   return 0;
}

bool is_chat_in_db(sqlite3* DB) {
    int exit = 0;
    exit = sqlite3_exec(DB, ("SELECT * FROM chats WHERE chat_id = " + to_string(message->chat->id)).c_str(), callback, 0, NULL);
    if (exit != SQLITE_OK) {
        cerr << "Error checking db!\n";
    }
    cout << callforward << endl;
    if (callforward == "") {
        callforward = "";
        return false;
    }
    else {
        callforward = "";
        return true;
    }
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

    file.close();

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

int main() {
    TgBot::Bot bot(token);

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("langhandler.db", &DB);
    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
    }
    else
        cout << "Opened Database Successfully!" << std::endl;


    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) { // If command /start
        string resp = get_msg(deflang, 0);
        bot.getApi().sendMessage(message->chat->id, resp);
    });

    bot.getEvents().onCommand("convert", [&bot](TgBot::Message::Ptr message) { // Main func for bot "/convert"
        if (is_trusted(message->from->username)) {
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

                bool is_recognized = true;
                string text;
                array<char, 128> buffer;
                FILE* pipe;
                if (deflang == "rus")
                    pipe = popen("Google-speech-api/.build/transcribe --bitrate 48000 --language-code ru audio.oga", "r");
                else
                    pipe = popen("Google-speech-api/.build/transcribe --bitrate 48000 audio.oga", "r");

                if (!pipe) {
                    is_recognized = false;
                    text = "Can't recognize voice.";
                }
                else {
                    cout << "Listening...\n";
                    while (fgets(buffer.data(), 128, pipe) != NULL) {
                        text += buffer.data();
                    }
                    cout << endl;
                }
                auto returnCode = pclose(pipe);
                if (text == "") {
                    is_recognized = false;
                    cout << "Text is empty.\n";
                    text = "Can't recognize voice.";
                }
                if (is_recognized)
                    text = "Recognized text: " + text;
                cout << text << "\n";
                cout << "Return code: " << returnCode << endl;
                
                bot.getApi().sendMessage(message->chat->id, text, false, message->replyToMessage->messageId); // Outputting recognized text.
            }
            else {
                bot.getApi().sendMessage(message->chat->id, "This command is used with reply to the voice message."); // If no replyed message and message isn't a voice message
            }
        }
        else {
            bot.getApi().sendMessage(message->chat->id, "You are not a trusted user. Write to the @khivus to get permission for /convert command.");
        }
    });

    bot.getEvents().onCommand("language", [&bot](TgBot::Message::Ptr message) { // If command /start
        string msg;
        if (deflang == "rus") {
            msg = "Выберите предпочетаемый язык.";
        }
        else {
            msg = "Select preferred language.";
        }
        bot.getApi().sendMessage(message->chat->id, msg);
    });

    bot.getEvents().onCommand("addtrusted", [&bot](TgBot::Message::Ptr message) {
        if (message->from->username == admin) {
            auto botmsg = bot.getApi().sendMessage(message->chat->id, "Reply to this message and type the trusted person username to add.");
            adding_trusted = true;
            cout << "Waiting response...\n";
            msgid = botmsg->messageId;
        }
    });

    bot.getEvents().onCommand("deltrusted", [&bot](TgBot::Message::Ptr message) {
        if (message->from->username == admin) {
            auto botmsg = bot.getApi().sendMessage(message->chat->id, "Reply to this message and type the trusted person username to delete.");
            deleting_trusted = true;
            cout << "Waiting response...\n";
            msgid = botmsg->messageId;
        }
    });

    bot.getEvents().onCommand("disptrusted", [&bot](TgBot::Message::Ptr message) {
        if (message->from->username == admin) {
            string user, users = "";
            ifstream file;
            file.open("trusted-users.txt", ifstream::in);
            while (!file.eof()) {
                file >> user;
                cout << user << " ";
                if (users == "")
                    users = "@" + user;
                else
                    users = users + "\n@" + user;
            }
            cout << endl;
            bot.getApi().sendMessage(message->chat->id, "List of a trusted users:\n" + users);
        }
    });

    // bot.getEvents().onCommand("testdb", [&bot](TgBot::Message::Ptr message) {
    //     if (message->from->username == admin) {
    //         bot.getApi().sendMessage(message->chat->id, "Testing...");
    //             sqlite3* DB;
    //             int exit = 0;
    //             char* messageError;
    //             exit = sqlite3_open("langhandler.db", &DB);
    //             string sql;
    //             long int cid = message->chat->id;

    //             if (exit) {
    //                 cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
    //             }
    //             else
    //                 cout << "Opened Database Successfully!" << std::endl;

    //             sql = string("INSERT INTO chats VALUES(") + to_string(cid) + ", '" + deflang + "');";
    //             exit = sqlite3_exec(DB, sql.c_str(), NULL, NULL, &messageError);
    //             if (exit != SQLITE_OK) {
    //                 std::cerr << "Error Insert" << std::endl;
    //                 sqlite3_free(messageError);
    //             }
    //             else
    //                 std::cout << "Records created Successfully!" << std::endl;

    //             sqlite3_close(DB);
    //     }
    // });


    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        if(is_chat_in_db(DB)) {
            sqlite3_exec(DB, (string("INSERT INTO chats VALUES(") + to_string(message->chat->id) + ", '" + deflang + "')").c_str(), NULL, 0, NULL);
            bot.getApi().sendMessage(message->chat->id, "If you want to change bot language use /language command.");
        }
        if (StringTools::startsWith(message->text, "/")) 
            cout << message->from->username << " used command: " << message->text.c_str() << endl;
        else if (message->text == "" && message->voice) {
            cout << message->from->username << " send a voice message." << endl;
        }
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

                bot.getApi().sendMessage(message->chat->id, "Added user @" + msg);
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

                bot.getApi().sendMessage(message->chat->id, "Deleted user @" + msg);
            }
            else if (msgid != message->replyToMessage->messageId) {
                bot.getApi().sendMessage(message->chat->id, "Please, reply to the CORRECT message!");
            }
        }
        else if ((adding_trusted || deleting_trusted) && message->from->username == admin && !message->replyToMessage) {
            bot.getApi().sendMessage(message->chat->id, "Please, reply to the specified message with needed username!");
        }
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