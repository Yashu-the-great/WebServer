//
//  webserver.hpp
//  WebServer
//
//  Created by Yashu Maurya on 22/05/22.
//

#ifndef webserver_hpp
#define webserver_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "../Networking/Socket.hpp"

extern "C" {
    int isFileThere(char* path) {
        FILE *file = fopen(path, "r");
        if(file) {
            fclose(file);
            return 1;
        } return 0;
    }
    
}
#endif /* webserver_hpp */
