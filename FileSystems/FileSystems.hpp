
#ifndef FileSystems_hpp
#define FileSystems_hpp

#include <string.h>
#include <string>
#include <unordered_map>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>

namespace FileSystem {
    char* get_request_header_file(char* response);
    char* get_extension(char* fileName);
    char* get_mime(char* fileName);
    char* getFilePath(char* socketRequest);
    char* file_to_buffer(char* filePath);
}
#endif