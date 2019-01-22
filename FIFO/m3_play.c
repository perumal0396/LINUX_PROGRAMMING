
///////////////////////////////////....writen by PERUMAL R......//......date.......22-01-2019..../////////// 
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

	ssize_t ret_read, ret_write;           //This one read and write permission only

	fk = mknod("fifo1",0674|S_IFIFO,0);    //create a FIFO

        perror("mknod: ");                     //Last execution of processor
      
	fd = open("./linux.mp3",O_RDONLY);     //This is open system call function

        perror("open: ");                     //Last execution of processor

	ret_read = read(fd,buffer,3528548);  //This is read system call function

        perror("read:");                     //Last execution of processor   

	fd1=open("fifo1",O_WRONLY);          //open system call it take read and write  
	                                 
	ret_write = write(fd1,buffer,3528548);

	perror("write:");  	           //Last execution of write processor

        close(fd);                         //close file descripted
	  
	close(fd1);                        //close file descripted
	
}
