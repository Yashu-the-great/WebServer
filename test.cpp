#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// #include "FileSystems/FileSystems.hpp"
// #include "Networking/Socket.hpp"
using namespace std;
// using namespace FileSystem;
// using namespace WS;
int main(void)
{
    printf("Getting Picture Size\n");
    FILE *picture;
    picture = fopen("./Build/images.jpeg","r");
    int size;
    fseek(picture, 0, SEEK_END);
    size = ftell(picture);
    fseek(picture, 0, SEEK_SET);
    printf("Sending Picture Size\n");
    printf("Size => %i", size);
    printf("Sending Picture as Byte Array\n");
    char send_buffer[size];
    while(!feof(picture)) {
        fread(send_buffer, 1, sizeof(send_buffer), picture);
        for(char c: send_buffer) {
            printf("%c", c);
        }
    }
    return 0;
}