
 /***************************************#
 #  Author      : PERUMAL.R              #
 #  Date        : 26-jan-2019            #
 #  Filename    : lsrid                  #
 #  Description : ls out the directory   #
 #                                       #
 #***************************************/



#include "lsrid.h"
int main(int argc,char *argv[])              //command argument
{
	struct dirent *dir;
	DIR *ptr;
	int fd,i;
	char str1[]="."; char str2[]="..";     //str1 current directory and str2 parent directory

	if(argc==1)
	{
		ptr=opendir(".");                //the opendir return the pointer to current directory
		perror("opendir : ");

		fd=strcmp(str1,str2);            //compare the two str1,str2
		perror("strcmp : ");

		dir=readdir(ptr);               //readdir function return to the pointer struct dirent
		perror("readdir : ");

		for(dir; dir!=NULL;  )
		{
			if(strcmp(dir->d_name,str1)!=0&&(strcmp(dir->d_name,str2)!=0))
				printf("%s\n",dir->d_name);
			dir=readdir(ptr);
		}
		//RID5 : close the directory stream
		closedir(ptr);
	}
	else if(argc>1)
	{
		for(i=1;i<argc;i++)
		{
			ptr=opendir(argv[i]);    
			perror("opendir : ");
		}
		//RID3 : Execute my_ls with argument pass to the next  argument  is a directory or not
		if(ptr==0)
		{
			printf("is NOT a Directory\n");
		}
		else if(ptr!=0)
		{                          
			fd=strcmp(str1,str2);    //compare the two str1,str2    
			perror("strcmp : ");

			dir=readdir(ptr);         //readdir function return to the pointer struct dirent
			perror("readdir : ");

			for(dir; dir!=NULL; )
			{
				if(strcmp(dir->d_name,str1)!=0&&(strcmp(dir->d_name,str2)!=0))
					printf("%s\n",dir->d_name);
				dir=readdir(ptr);
			}
			//RID5 : close the directory stream
			closedir(ptr);
		}
	}
}

