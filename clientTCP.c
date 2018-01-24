//
// Created by Xenoth on 24/01/2018.
//

#include "lib/fonctionsTCP.h"

void checkEnoughArgs(int argc);

int main(int argc, char **argv)
{

    checkEnoughArgs(argc);

    FonctionsTCP.init();
    SOCKET sock = FonctionsTCP.socketClient(argv[0], atoi(argv[1]));

    FonctionsTCP.end;
    return 0;
}

void checkEnoughArgs(int argc)
{
    if(argc < 2 ) {
        fprintf(stderr, "clientTCP:\tRequires two arguments : nomMachine and nPort\n");
        exit(EXIT_FAILURE);
    }
}