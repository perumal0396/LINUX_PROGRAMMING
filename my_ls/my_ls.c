    /********************************************/
    /*   Author       : PERUMAL.R               */
    /*   Date         : 25-jan-2019             */
    /*   Filename     : my_ls.c                 */
    /*   Description  : explain ls - list out   */
    /*                      directory           */     
    /********************************************/

#include "my_ls.h"
int main()
{
  struct dirent *dir;
  DIR *ptr;
  int fd;
  char str1[]="."; char str2[]="..";    // strcmp str1 is a curent directroystr2 parent directory

   //opendir() function open directory stream and than directory name
      ptr=opendir("/home/linux/namedpipe/fifo/msg_que/msgctl");
      perror("opendir: ");

   //the strcmp is a compare to two string in the directory
      fd=strcmp(str1,str2);
      perror("strcmp : ");

    // readdir() function return a pointer to dirent structure
      dir=readdir(ptr);
      perror("readdir: ");
   
   
    //It returns NULL on reaching  the  end  of  the  directory  stream  
    //given !=NULL because need to print all directory and files

      for(dir; dir!=NULL;  )
      {	     
	     if(strcmp(dir->d_name,str1)!=0&&(strcmp(dir->d_name,str2)!=0))

	       printf(" %s\n",dir->d_name);

	       dir=readdir(ptr);	    
      }
      closedir(ptr); //close function and end of program
}
