//
//  webserver.cpp
//  WebServer
//
//  Created by Yashu Maurya on 22/05/22.
//

#include "webserver.hpp"
#include "../colors.h"

using namespace WS;

int main(void) {
    Socket socket = Socket(AF_INET, SOCK_STREAM, 0, 6969,  INADDR_ANY, 5);
    int val_read;
    while(1) {
        // simple echo code.
        green();
        printf("Listening : \n\n");
        reset();
        socket.startAccept(socket.get_sock(), socket.get_address());
        socket.recieve();
        printf("%s\n",socket.buffer);
        char* hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
        socket.send(hello);
        close(socket.get_websocket());
    }
    return 0;
}
