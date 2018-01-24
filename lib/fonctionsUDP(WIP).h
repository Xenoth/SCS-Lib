/*
 **********************************************************
 *
 *  Programme : fonctionsUDP.h
 *
 *  ecrit par : LP,VF.
 *
 *  resume :    entete des fonction d'initialisation des sockets en mode 
 *              non connecte
 *
 *  date :      12 / 01 / 18
 *
 ***********************************************************
 */ 

#ifndef FONCTIONS_UDP_H
#define FONCTIONS_UDP_H

/* include generaux */
#include <sys/types.h>

/* include add socket */
#include <sys/socket.h>

/*
***************************************************************
 *
 *  fonction : socketUDP(numero de port)
 *
 *  resume :   creer et retourner une socket associee 
 *             a une adresse locale
 *              
 **************************************************************
 */

int socketUDP(ushort port);

/*
 **********************************************************
 *
 *  fonction :  initAddr(nom machine, numero de port)
 *
 *  resume :    creer une adresse de socket pour 
 *              une machine et un numero de port
 *              (adresse retournee par effet de bord)
 *
 **********************************************************
 */

struct sockaddr_in* initAddr(char* machine, ushort port);
/*
************************************************************************
 *
 *  fonction :  adresseUDP(nom machine, numero de port, adresse socket)
 *
 *  resume :    creer une adresse de socket pour 
 *              une machine et un numero de port
 *              (adresse retournee par parametre)
 *              
 ***********************************************************************
 */
int adresseUDP(char* machine, ushort port, struct sockaddr_in* padd);

#endif
