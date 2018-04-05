#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
#define NUM_THREADS     5
void *print_hello(void *threadid)
{
	long tid;
	tid = (long) threadid;
	while(1){
		printf("Hello World! It's me, thread #%ld!\n", tid);
		sleep(5);
		}
	pthread_exit(NULL);
}
int main (int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	long t;
	for (t = 0; t < NUM_THREADS; t++)	
	{
		printf("In main: creating thread %ld\n", t);
		pthread_create(threads + t, NULL, print_hello, (void *) t);
		
	}
	pthread_exit(NULL);
}
