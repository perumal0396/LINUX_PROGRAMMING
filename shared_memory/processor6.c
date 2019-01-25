  /***********************************#
   #  Author      : PERUMAL.R         #
   #  Date        : 22-jan-2019       #
   #  Filename    : shared_memory     #
   #  Description : send a give string#
   #                 to processor6    #
   #**********************************/


#include "shared_memory.h"

char Buffer[8192]=" ";
char Buffer1[8192]=" ";
char Buffer2[8192]=" ";
char Buffer3[8192]=" ";
char Buffer4[8192]=" ";
char Buffer5[8192]=" ";
int main()
{
	int i,j=0,shmid1;
	char *data_ptr;
	mqd_t mqopen;
	ssize_t recv;	
	unsigned int prio;
	struct mq_attr my_attr;
     
	//we are sending 2 parameters only if we create a new message queue ,we send to 4 parameters
	mqopen=mq_open("/posix1",O_RDWR);  //name of message queue must be starting with /and open a message queue

	recv=mq_receive(mqopen,Buffer,8192,&prio);
	strcpy(&Buffer5[j],Buffer);                 //copy the message buffer to buffer5 using strcopy function call
	for(i=0;Buffer[i]!='\0';i++)
		j++;

	printf("%ld\n",my_attr.mq_msgsize);
	printf("proirity=%u\n %s\n",prio,Buffer);

	mqopen=mq_open("/posix2",O_RDWR);
	perror("mq_open: ");

	recv=mq_receive(mqopen,Buffer1,8192,&prio);
	strcpy(&Buffer5[j],Buffer1);
	for(i=0;Buffer1[i]!='\0';i++)          //copy the message bufer1 to buffer5 using string copy
		j++;

	printf("%ld\n",my_attr.mq_msgsize);
	printf("proirity=%u %s\n",prio,Buffer1);

	mqopen=mq_open("/posix3",O_RDWR);
	perror("mq_open: ");

	recv=mq_receive(mqopen,Buffer2,8192,&prio);
	strcpy(&Buffer5[j],Buffer2);
        for(i=0;Buffer2[i]!='\0';i++)            //copy the message buffer2 to buffer5 using string copy
		j++;

	printf("%ld\n",my_attr.mq_msgsize);
	printf("proirity=%u %s\n",prio,Buffer2);

	mqopen=mq_open("/posix4",O_RDWR);
	perror("mq_open: ");

	recv=mq_receive(mqopen,Buffer3,8192,&prio);
	strcpy(&Buffer5[j],Buffer3);             //copy the messagebuffer3 to buffer5 using string copy
	for(i=0;Buffer3[i]!='\0';i++)
               j++;

	printf("%ld\n",my_attr.mq_msgsize);
	printf("proirity=%u %s\n",prio,Buffer3);

	mqopen=mq_open("/posix5",O_RDWR);
	perror("mq_open: ");

	recv=mq_receive(mqopen,Buffer4,8192,&prio);
	strcpy(&Buffer5[j],Buffer4);             //copy the messagebuffer4 to buffer5 using string copy
	for(i=0;Buffer4[i]!='\0';i++)
		j++;

	printf("%ld\n",my_attr.mq_msgsize);
	printf("proirity=%u %s\n",prio,Buffer4);
        Buffer5[j]='\0';

	printf("proirity %s\n",Buffer5);


        shmid1=shmget(101,8192,IPC_CREAT|S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);         

	//return virtual address shared_memory from shmat
        perror("shmget: ");
        data_ptr=shmat(shmid1,NULL,0);
        perror("shmat: "); 
       //copy some data into shared is address return from shmat
	strcpy(data_ptr,Buffer5);
	shmdt(data_ptr);
	perror("shmdt: ");

	return 0;
}


