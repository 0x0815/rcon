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
#include <unistd.h>
#include "rcon.h"

#define QUIET false
#define DEBUG true

int auth = 0;

int main(int argc, char *argv[]) {
    
    char *ip;
    short port;
    char *password;
    int ret = 0;
    int sock;
    struct sockaddr_in a;
    char *command = argv[argc];
    
    if(DEBUG){
        printf("%s: %i\n","argument number",argc);
        for (int i = 0; i < argc; i++)
            printf("%s\n", argv[i]);
    }
    
    if (argc == 0 || argc >=6) {
        if(!QUIET) printf("%s \n","Usage: rcon {ip} {port} {password}");
        exit(0);
    }
    
    if(!isValidIpAddress(argv[1])){
        if(!QUIET) printf("%s \n","Not a valid IP.");
        exit(0);
    }
    
    if (!isValidPort(argv[2])) {
        if(!QUIET) printf("%s \n","Not a valid port.");
        exit(0);
    }
    
    ip = argv[1];
    port = atoi(argv[2]);
    password = argv[3];
    
    a.sin_family = AF_INET;
    a.sin_addr.s_addr = inet_addr(ip);
    a.sin_port = htons(port);
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    ret = connect(sock, (struct sockaddr *) &a, sizeof(a));
    
    if (ret == -1) {
        if(!QUIET) printf("%s","Connection failed.\n");
    }else{
        if(!DEBUG) printf("%s","Connectet to Server.\n");
    }
    
    
   
    
    close(sock);
}

bool isValidIpAddress(char *ipAddress){
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}

bool isValidPort(char *port){
    for (int i = 0; i < strlen(port); i++) {
        if (!isdigit(port[i])) {
            return false;
        }
    }
    return true;
}




