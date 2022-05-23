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
        
        val_read = read(socket.get_websocket(), socket.buffer, sizeof(socket.buffer));
        
        printf("%s\n",socket.buffer);
        
        char* hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
        
        write(socket.get_websocket() , hello , strlen(hello));
        
        close(socket.get_websocket());
    }
    return 0;
}
