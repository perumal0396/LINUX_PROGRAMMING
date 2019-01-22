//////////////////////////////......writen by PERUMAL R.....//...date....22-01-2019

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
	int fd,fd1,fk;

	char buffer[3528548];

	ssize_t ret_read, ret_write;        //This one read and write permission only

	fd=open("fifo1",O_RDONLY);        //FIFO

	perror("open: ");                 //last execution of processor

	ret_read = read(fd,buffer,3528548);    //This is read system call function

        perror("read: ");                        // Last exection of processor  

	fd1 = open("7G.mp3",O_CREAT | O_WRONLY,0764);  // open system call it take create and write 

	perror("open: ");                  // last exection of procesor
 
	ret_write = write(fd1,buffer,3528548); //This is write system call function

	perror("write: ");

	close(fd);

	close(fd1);
}
