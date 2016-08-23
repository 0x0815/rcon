//
//  rcon.h
//  rcon
//
//  Created by Administrator on 23.08.16.
//  Copyright © 2016 DontPlayAlone.de. All rights reserved.
//

#ifndef rcon_h
#define rcon_h

bool isValidIpAddress(char *ipAddress);
bool isValidPort(char *port);
bool sendRcon(int sock, int id, int packetType, char *command);

#endif /* rcon_h */
