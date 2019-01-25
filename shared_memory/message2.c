 /********************************#
 #   Author      : PERUMAL.R      #
 #   Date        : 22-jan-2019    #
 #   Filename    : shared_memory  #
 #   Description : message 2      #
 #********************************/

#include "shared_memory.h"

char message2[ ]= "MESSAGE FROM PROCESSOR2\n";
int main()
{
	int ret;
	mqd_t mqopen;
	struct mq_attr my_attr;

	my_attr.mq_maxmsg=101;         //max number of message in queue
	my_attr.mq_msgsize=1024;       // max size of message

	//name of message queue 
	mqopen=mq_open("/posix2",O_CREAT|O_RDWR,0644,NULL); //create a new posix message queue or opens and existing queue
	perror("mq_open: ");

	ret=mq_send(mqopen,message2,strlen(message2)+1,101);  //send a message to message queue
	perror("msq_send: ");

	ret=mq_close(mqopen);    // close a message queue description
	perror("mq_close: ");
  
}



