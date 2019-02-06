 /***************************************/
 /* Author      : PERUMAL.R             */
 /* Date        : 05-FEB-2019           */
 /* Filename    : thread.c              */
 /* Description : explain create thread */
 /***************************************/

#include "pthread.h"

 //Global variable declaration

 // function definition
static void * threadfun(void *arg)
{
	unsigned long long int *ptr =( unsigned long long int *)arg;	

	unsigned long long int i,k=0;
	for(i=0;i<*ptr;i++)
	{
		k+=i;
        	printf(" %lld\n", k);
	}	
}
int main(int argc , char *argv[])
{
	int s;
	void *res;
	unsigned long long int input=65535;
	pthread_t t1;
       // create a new thread  

	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
        s = pthread_create(&t1,NULL,threadfun,&input);
	perror("pthread_create: ");

        //join with a terminated thread

	s=pthread_join(t1,&res);
	perror("pthread join: ");

	printf(" %ld\n",(long)res);
//	exit(EXIT_SUCCESS);
}

