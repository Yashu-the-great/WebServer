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
            cout << socket.buffer << endl;
            // char* file = get_request_header_file(socket.buffer);
            char* filePath = getFilePath(socket.buffer);
            if(strstr(socket.buffer, "/ ") != NULL) {
                strcat(filePath,"t.html");
                socket.sendFile(filePath);
            } else {
                socket.sendFile(filePath);
            }
        }
        socket.stop();
    }
    return 0;
}
