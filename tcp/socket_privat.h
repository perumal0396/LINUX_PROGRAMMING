
 /***************************************/
 /* Author      : PERUMAL.R             */
 /* Date        : 024-FEB-2019          */
 /* Filename    : socket.h              */
 /* Description : explain privat chat   */
 /***************************************/

//include header files

#ifndef SOCKET_PRIVAT_H
#define SOCKET_PRIVAT_H

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<error.h>
#include<pthread.h>

void *send_fun(); //msg send fun

void *recv_fun(); //msg recive fun

// user define datatype

#endif //socket_privat_h


