//
//  ClientSocket.cpp
//  WebServer
//
//  Created by Yashu Maurya on 23/05/22.
//

#include "ClientSocket.hpp"

CWS::ClientSocket::ClientSocket(int domain, int type, int protocol, int port, char* addr) {
    client_sock = socket(domain, type, protocol);
    checkError(client_sock);
    configureClientAddress(domain, port);
    checkAddress(domain, addr, client_address);
    connection = clientConnect(client_sock, client_address);
    checkError(connection);
}

void CWS::ClientSocket::checkError(int value) {
    if (value < 0) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

void CWS::ClientSocket::configureClientAddress(int domain, int port) {
    memset(&client_address, '\0', sizeof(client_address));
    client_address.sin_family = domain;
    client_address.sin_port = htons(port);
    memset(&buffer, '\0', sizeof(buffer));
}

void CWS::ClientSocket::checkAddress(int domain, char* addr, struct sockaddr_in address) {
    if(inet_pton(domain, addr, &address.sin_addr) < 0) {
        perror("Invalid Address");
        exit(EXIT_FAILURE);
    }
}

int CWS::ClientSocket::clientConnect(int sock, struct sockaddr_in address) {
    return connect(sock, (struct sockaddr *) &address, sizeof(address));
}

int CWS::ClientSocket::get_client_sock() {
    return client_sock;
}

struct sockaddr_in CWS::ClientSocket::get_client_address() {
    return client_address;
}

int CWS::ClientSocket::get_connection() {
    return connection;
}
