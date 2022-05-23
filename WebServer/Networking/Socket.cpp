//
//  Socket.cpp
//  WebServer
//
//  Created by Yashu Maurya on 23/05/22.
//

#include "Socket.hpp"

WS::Socket::Socket(int domain, int type, int protocol, int port, u_long addr, int backlog) {
    
    sock = makeSocket(domain, type, protocol);
    checkError(sock);
    configureSocketAddress(domain, addr, port);
//    address.sin_family = AF_INET;
//    address.sin_addr.s_addr = INADDR_ANY;
//    address.sin_port = htons(6969);
    connection = bindSocket(sock, address);
    checkError(connection);
    lstn = startListen(sock, backlog);
}

int WS::Socket::makeSocket(int domain, int type, int protocol) {
    return socket(domain,type, protocol);
}

void WS::Socket::checkError(int value) {
    if(value < 0) {
        perror("Error detected");
        exit(EXIT_FAILURE);
    }
}


int WS::Socket::bindSocket(int sock, struct sockaddr_in address) {
    return bind(sock, (struct sockaddr *) &address, sizeof(address));
}

void WS::Socket::configureSocketAddress(int sin_family, u_long addr, int port) {
    address.sin_family = sin_family;
    address.sin_addr.s_addr = htonl(addr);
    address.sin_port = htons(port);
    memset(address.sin_zero, '\0', sizeof(address.sin_zero));
}

int WS::Socket::startListen(int sock, int backlog) {
    return listen(sock, backlog);
}

int WS::Socket::get_sock() {
    return sock;
}

int WS::Socket::get_connection() {
    return connection;
}

struct sockaddr_in WS::Socket::get_address() {
    return address;
}

int WS::Socket::startAccept(int sock, struct sockaddr_in address) {
    socklen_t address_size = sizeof(address);
    u_int val = accept(sock, (struct sockaddr *) &address, &address_size);
    checkError(val);
    return (int) val;
}
