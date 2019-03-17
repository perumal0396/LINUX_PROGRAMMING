
 /***************************************/
 /* Author      : PERUMAL.R             */
 /* Date        : 024-FEB-2019          */
 /* Filename    : socket.h              */
 /* Description : explain privat chat   */
 /***************************************/

//include header files

#ifndef CLIENT_PRIVATE_H
#define CLIENT_PRIVATE_H

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

void *send_fun();//message send

void *recv_fun();//message recive

// user define datatype

#endif //socket_private_h


