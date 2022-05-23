//
//  webserver.cpp
//  WebServer
//
//  Created by Yashu Maurya on 22/05/22.
//

#include "webserver.hpp"

using namespace WS;

int main(void) {
    Socket socket = Socket(AF_INET, SOCK_STREAM, 0, 6969,  INADDR_ANY, 5);
   
    int new_socket;
    int val_read;
    
    
    while(1) {
        printf("starting webserver");
        new_socket = socket.startAccept(socket.get_sock(), socket.get_address());
        memset(socket.buffer, '\0', sizeof(socket.buffer));
        val_read = read(new_socket, socket.buffer,sizeof(socket.buffer));
        printf("%s\n",socket.buffer);
        char* hello = "Hello there";
        write(new_socket , hello , strlen(hello));
        close(new_socket);
    }
    return 0;
}
