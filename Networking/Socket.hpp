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
#include <unistd.h>
#include <string.h>
#include "../FileSystems/FileSystems.hpp"

namespace WS {

enum protocol {
    TCP,
    UDP
};

// For Sockets
class Socket {
private:
    int sock;
    int connection;
    int lstn;
    int websocket;
    struct sockaddr_in address;

public:
    char buffer[100000];
    Socket(int domain, int type, int protocol, int port, u_long addr, int backlog);
    Socket(enum protocol p, int port, int backlog);
    int makeSocket(int domain, int type, int protocol);
    void configureSocketAddress(int sin_family, u_long addr, int port);
    void configureSocketAddress(int sin_family, char* addr, int port);
    void checkError(int value);
    int bindSocket(int sock, struct sockaddr_in address);
    int startListen(int sock, int backlog);
    void startAccept(int sock, struct sockaddr_in address);
    int get_sock();
    int get_connection();
    int get_websocket();
    int send(char* message);
    int send(char* message, int size);
    int recieve();
    void recieve(char* user_buffer);
    void stop();
    struct sockaddr_in get_address();

    int sendFile(char* filePath);
 };
}
#endif /* Socket_hpp */
