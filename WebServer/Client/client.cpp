//
//  client.cpp
//  WebServer
//
//  Created by Yashu Maurya on 23/05/22.
//

#include "client.hpp"

using namespace CWS;

int main(void) {
    
    ClientSocket client = ClientSocket(AF_INET, SOCK_STREAM, 0, 6969, "localhost");
    char* hello = "Hello there buddy";
    send(client.get_client_sock(), hello, strlen(hello), 0);
    int value = read(client.get_client_sock(), client.buffer, sizeof(client.buffer));
    printf("%s", client.buffer);
    return 0;
}
