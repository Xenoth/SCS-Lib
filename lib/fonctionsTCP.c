//
// Created by xenoth on 17/01/18.
//


#include "fonctionsTCP.h"

static void init(void)
{
    #ifdef WIN32
        WSADATA wsa;
        int err = WSAStartup(MAKEWORD(2, 2), &wsa);
        if(err < 0)
        {
            fprintf(stderr, "fonctionsTCP::init:\tWSAStartup failed");
            exit(EXIT_FAILURE);
        }
    #endif
}

static void end(void)
{
    #ifdef WIN32
        WSACleanup();
    #endif
}


SOCKET socketServeur(unsigned short nPort)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == SOCKET_ERROR) {
        fprintf(stderr, "fonctionsTCP::socketServeur:\tUnable to create the socket\n");
        return EXIT_FAILURE;

    }
    SOCKADDR_IN serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = nPort;

    int err = bind(sock, (SOCKADDR *) &serv_addr, sizeof(SOCKADDR));

    if(err < 0) {
        fprintf(stderr, "fonctionsTCP::socketServeur:\tUnable to bind the socket\n");
        return EXIT_FAILURE;

    }

    return sock;
}

SOCKET socketClient(char *nomMachine, unsigned short nPort)
{
    SOCKADDR_IN serv_addr;
    struct hostent *server;

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == SOCKET_ERROR) {
        fprintf(stderr, "fonctionsTCP::socketClient:\tUnable to create the socket\n");
        return EXIT_FAILURE;
    }

    server = gethostbyname(nomMachine);
    if (server == NULL) {
        fprintf(stderr, "fonctionsTCP::socketClient:\tUnknown host \"%s\"\n", nomMachine);
        return EXIT_FAILURE;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *(struct in_addr *) server->h_addr;
    serv_addr.sin_port = nPort;

    if (connect(sock,(SOCKADDR *) &serv_addr,sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        fprintf(stderr, "fonctionsTCP::socketClient:\tUnable to connect to the server \"%s\"\n", nomMachine);
        return EXIT_FAILURE;
    }

    return sock;
}

struct fonctions_tcp FonctionsTCP = {
        .init = init,
        .end = end,
        .socketClient = socketClient,
        .socketServeur = socketServeur,
};

