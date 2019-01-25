 /*******************************#
 #  Author      : PERUMAL.R      #
 #  Date        : 22-jan-2019    #
 #  Filename    : shared_memory  #
 #  Description : proessor7      #
 #*******************************/



#include "shared_memory.h"
int main()
{
	int shmid1;
	char data[300];
	char *data_ptr;
	shmid1=shmget(101,8192,0);   //rw-r--r-permission 0644
	perror("shmget:");

	//return the virtual address shared memory is mapped
	data_ptr=shmat(shmid1,NULL,0);
	perror("shmat:");

	//copy some data into shard memory is address return shmat
	strcpy(data,data_ptr);
	printf("%s\n",data);

	shmdt(data_ptr);
	perror("shmdt:");
	return 0;
}



