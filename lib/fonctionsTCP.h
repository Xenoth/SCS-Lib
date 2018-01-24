//
// Created by xenoth on 17/01/18.
//

#ifndef FONCTIONSTCP_H
#define FONCTIONSTCP_H

#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32

#include <winsock2.h>

#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error not defined for this platform

#endif

struct fonctions_tcp
{
    void (*init)(void);
    void (*end)(void);

    SOCKET (*socketServeur)(unsigned short nPort);
    SOCKET (*socketClient)(char *nomMachine, unsigned short nPort);
};

extern struct fonctions_tcp FonctionsTCP;



#endif //FONCTIONSTCP_H
