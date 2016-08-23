//
//  main.c
//  rcon
//
//  Created by xass on 22.08.16.
//  Copyright © 2016 DontPlayAlone.de. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <ctype.h>
#include "rcon.h"

#define QUIET false
#define DEBUG true

int main(int argc, char *argv[]) {
    
    if (argc <= 0) {
        printf("%s \n","Usage: rcon {ip} {port} {password}");
        exit(0);
    }
    
    if(!isValidIpAddress(argv[1])){
        printf("%s \n","Not a valid IP.");
        exit(0);
    }
    
    if (!isdigit(argv[2])) {
        printf("%s \n","Not a valid port.");
    }
}

bool isValidIpAddress(char *ipAddress){
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}
