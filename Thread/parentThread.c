/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: main.c                      */
/*   OS Assignment				       */
/*  ================================== */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
* Struct serves as storage since we can only parse one pointer to threads
*
*/
typedef struct
{
	char buffer1[15];
	char buffer2[15];
	
} Buffers;

void *runA(void *arg)
{

	printf("Hello from the first thread :D\n");
	Buffers *bf = (Buffers*) arg;


	printf("echo: %s\n", bf->buffer1); //debug
	system("../PP/./PP"); //runs PP sim
	//system(bf->buffer);
	//pthread_mutex_unlock(&main);

	return NULL;
}

void *runB(void *arg)
{
	printf("hello from the second thread :)\n");
	//system("../SRTF/./SRTF"); //runs SRTF sim

	/*
	int *num = (int *) value;
	printf("The value of num is %d\n", *num);
	*/
	return NULL;
}

int main(int argc, char **argv)
{
	Buffers bf; //Struct used to store buffers
	pthread_t threadA; //thread ID
	//pthread_t threadB;
	
	printf("Enter a valid filename or QUIT\n");
	scanf("%s", bf.buffer1);
	

	//creates new threads
	//thread ID, thread attributes, function to run, arguments (pointer)
	pthread_create(&threadA, NULL, runA, &bf);
	//wait until thread work is done
	pthread_join(threadA, NULL);

	//pthread_create(&threadB, NULL, runB, buffer1);
	//pthread_mutex_lock(&runB);

	
	
	
	return EXIT_SUCCESS;
}


/*
void suspendMe()
{ // tell the thread to suspend
    pthread_mutex_lock(&runB);
    //m_SuspendFlag = 1;
    pthread_mutex_unlock(&runB);
}
void resumeMe()
{ // tell the thread to resume
    pthread_mutex_lock(&runB);
    //m_SuspendFlag = 0;
    //phtread_cond_broadcast(&m_ResumeCond);
    pthread_mutex_unlock(&runB);
}
*/
/*
void checkSuspend()
{ // if suspended, suspend until resumed
    pthread_mutex_lock(&m_SuspendMutex);
    while (m_SuspendFlag != 0) pthread_cond_wait(&m_ResumeCond, &m_SuspendMutex);
    pthread_mutex_unlock(&m_SuspendMutex);
}
*/
