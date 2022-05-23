//
//  Socket.hpp
//  WebServer
//
//  Created by Yashu Maurya on 23/05/22.
//

#ifndef Socket_hpp
#define Socket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>

namespace WS {
class Socket {
private:
    int sock;
    int connection;
    int lstn;
    int websocket;
    struct sockaddr_in address;

public:
    char buffer[30000];
    Socket(int domain, int type, int protocol, int port, u_long addr, int backlog);
    int makeSocket(int domain, int type, int protocol);
    void configureSocketAddress(int sin_family, u_long addr, int port);
    void checkError(int value);
    int bindSocket(int sock, struct sockaddr_in address);
    int startListen(int sock, int backlog);
    void startAccept(int sock, struct sockaddr_in address);
    int get_sock();
    int get_connection();
    int get_websocket();
    struct sockaddr_in get_address();
};
}
#endif /* Socket_hpp */
