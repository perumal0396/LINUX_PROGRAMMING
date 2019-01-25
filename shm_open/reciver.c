
  /************************************#
  #  Author      : PERUMAL.R           # 
  #  Date        : 23-jan-2019         #
  #  FileName    : shm_reciver.c       #
  #  Description : Explains            #
  #                posix shared memory #
  #************************************/



#include "header_posix.h"

int main()
{
	int fd,sync,fd1,tem;
        unsigned char str[100]; 
	unsigned char *data_ptr;

	fd=shm_open("/Poisx",O_RDWR,0644);    //create or open posix shard memory

        perror("shm_open: ");                //print the last system call function

 	data_ptr=mmap(NULL,25,PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);  //create a new mapping in the address space of the calling processor 	
	perror("mmap: ");

        printf("%s\n",data_ptr);           //print the address and string

	tem=msync(data_ptr,25,MS_SYNC);  //my_sync request an update (posix flags)
	perror("msync: ");

	shm_unlink("/posix");            //it remove a shared memory object 

	return 0;
}

