//
//  webserver.cpp
//  WebServer
//
//  Created by Yashu Maurya on 22/05/22.
//
#include "webserver.hpp"
#include "../colors.h"

using namespace WS;
using namespace std;
using namespace FileSystem;
int main(void) {

    Socket socket = Socket(AF_INET, SOCK_STREAM, 0, 8000, INADDR_ANY, 5);
    while(1) {
        green();
        printf("[+] Listening [+] \n\n");
        reset();
        socket.startAccept(socket.get_sock(), socket.get_address());
        if(socket.recieve() != -1) {
            puts("\n\n-------------------- Request Recieved --------------------\n");
            cout << "Request :: \n" << socket.buffer << endl;
            char* filePath = getFilePath(socket.buffer);
            
            cout << "Server requested the following file : " << filePath << endl;
            if(strstr(socket.buffer, "/ ") != NULL) {
                strcat(filePath,"index.html");
                socket.sendFile(filePath);
            } else {
                socket.sendFile(filePath);
            }
        }
        socket.stop();
        puts("\n\n-------------------- Request Served --------------------\n");

    }
    return 0;
}
