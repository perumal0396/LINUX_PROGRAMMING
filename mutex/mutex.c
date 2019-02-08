  /***************************************/
  /* Author      : PERUMAL.R             */
  /* Date        : 07-FEB-2019           */
  /* Filename    : mutex.c               */
  /* Description : explain mutex thread  */
  /***************************************/


#include "pthread.h"

/*global variable definition */
static int  input=0;

/*mutex is a variable pthread_mutex */
static pthread_mutex_t mut;

static void * threadfun(void *arg)
{
	int ptr =*((int *)arg);
	int m,j,s;
	for(j=0;j<ptr;j++)
	{
		/* pthread_mutex_lock is lock thread in unlock function */

		s=pthread_mutex_lock(&mut);
		m=input;
		m++;
		input=m;
		s=pthread_mutex_unlock(&mut);
	}

}
int main(int argc,char *argv[])
{
	pthread_t t1,t2;

	int s,ptr=10000;

	/*create a first thread and call the threadfun */
	s = pthread_create(&t1,NULL,threadfun,&ptr);
	perror("pthread_create : ");

       /*create a second thread and call the threadfun */
	s = pthread_create(&t2,NULL,threadfun,&ptr);
	perror("pthread_create : ");
 
	s=pthread_join(t1,NULL);
	perror("pthread_jion : ");
       
	/*join the thread */
	s=pthread_join(t2,NULL);
	perror("pthread_jion: ");

        printf("input=%d\n ",input);

}
