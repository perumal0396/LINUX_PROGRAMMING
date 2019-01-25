  /*********************************#
  #  Author       : PERUMAL.R       #
  #  Date         : 22-jan-2019     #
  #  Filename     : shared_memory   #
  #                 message1        #
  #*********************************/


#include "shared_memory.h"

char message1[ ]= "MESSAGE FROM PROCESSOR1\n"; //maximum size of themessage

int main()
{
	int ret;

	mqd_t mqopen;             //mqd_t(message queue descriptor(and than mqopen function

	struct mq_attr my_attr;  // argument

	my_attr.mq_maxmsg=101;    //max number of string size message in queue

	my_attr.mq_msgsize=1024;  //size of message

	mqopen=mq_open("/posix1",O_CREAT|O_RDWR,0644,NULL);  //mq_open is a system call used to create or open posix message queue 
	perror("mq_open: ");

	ret=mq_send(mqopen,message1,strlen(message1)+1,101); //send amessage to a message queue
        perror("msq_send: ");  //last system call function

	ret=mq_close(mqopen); // close a message queue description
	perror("mq_close: ");
  
}



