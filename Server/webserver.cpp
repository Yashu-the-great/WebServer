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
int main(void) {

    Socket socket = Socket(AF_INET, SOCK_STREAM, 0, 6969, INADDR_ANY, 5);
    char* html;
    FILE *fp = fopen("/Users/yashumaurya/Documents/Cpp/WebServer/Server/t.html", "r");
    long size;
    if(fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    html = (char *) calloc(size, sizeof(char));
    fread(html, sizeof(char), size, fp);
    fclose(fp);

    while(1) {
        // simple echo code.
        green();
        printf("[+] Listening [+] \n\n");
        reset();
        socket.startAccept(socket.get_sock(), socket.get_address());
        if(socket.recieve() != -1) {
            cout << socket.buffer << endl;
            socket.send("HTTP/1.1 200 OK\nConnection: close\nContent-Type: text/html\r\n\r\n");
            socket.send(html);
        }
        // printf("%s\n",socket.buffer);
        // socket.send((char *) html.c_str());
        socket.stop();
    }
    return 0;
}
