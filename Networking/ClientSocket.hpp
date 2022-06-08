//
//  ClientSocket.hpp
//  WebServer
//
//  Created by Yashu Maurya on 23/05/22.
//

#ifndef ClientSocket_hpp
#define ClientSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>

namespace CWS {
class ClientSocket {
private:
    int client_sock;
    struct sockaddr_in client_address;
    int connection;
public:
    char buffer[30000];
    ClientSocket(int domain, int type, int protocol, int port, char* addr);
    void checkError(int value);
    void configureClientAddress(int domain, int port);
    void checkAddress(int domain, char* addr, struct sockaddr_in address);
    int clientConnect(int sock, struct sockaddr_in address);
    int get_client_sock();
    struct sockaddr_in get_client_address();
    int get_connection();
};
}

#endif /* ClientSocket_hpp */
