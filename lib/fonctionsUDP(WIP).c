//
// Created by xenoth on 24/01/18.
//

#include "fonctionsUDP.h"

int socketUDP(ushort port)
{
    struct sockaddr_in my_socket_addr;
    int socketFD, error = 0;

    socketFD = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(socketFD < 0)
    {
        fprintf(stderr, "fonctionsUDP::socketUDP:\tUnable to create the socket\n");
        return EXIT_FAILURE;
    }

    my_socket_addr.sin_family = AF_INET;
    my_socket_addr.sin_port = htons(port);
    my_socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    error = bind(socketFD , (struct sockaddr*)&my_socket_addr, sizeof(struct sockaddr_in));

    if(error < 0)
    {
        printf(stderr, "fonctionsTCP::socketServeur:\tUnable to bind the socket\n");
        return EXIT_FAILURE;
    }

    return socketFD;
}

struct sockaddr_in* initAddr(char* machine, ushort port)
{

}

int adresseUDP(char* machine, ushort port, struct sockaddr_in* padd)
{

}