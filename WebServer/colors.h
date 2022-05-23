//
//  colors.h
//  WebServer
//
//  Created by Yashu Maurya on 23/05/22.
//

#ifndef colors_h
#define colors_h

extern "C" {
#include <stdio.h>

void reset() {
    printf("\033[0m ");
}

void red() {
    printf("\033[0;31m ");
}
void green() {
    printf("\033[0;32m");
}

}

#endif /* colors_h */
