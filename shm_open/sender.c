             			              	                     
 /*************************************#
 #  Author      : PERUMAL.R            #
 #  Date        : 23-jan-2019          #
 #  FileName    : shm_sender.c         #
 #  Description : Explains             #
 #                posix shared memory  #
 #*************************************/


 #include "header_posix.h"

unsigned char str[]="TIME IS GOLD KEEP TIME\n";

int main()
{
	int fd,fd1,tem;

	unsigned char *data_ptr;

	ssize_t ret_write;               //write permission only   

	fd=shm_open("/Poisx",O_CREAT | O_RDWR,0644); //create or open shared memory
        perror("shm_open: ");              // last system call open function

        ret_write=write(fd,str,strlen(str));  //write content using file descriptor
	perror("write: ");

	data_ptr=mmap(NULL,25,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0); //create a new mapping in the virtual address space of the calling process   
	perror("mmap: ");

        tem=msync(data_ptr,25,MS_SYNC);  //my_sync request and update(posix flags)
	perror("msync: ");

	return 0;
}


