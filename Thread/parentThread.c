/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: main.c                      */
/*   OS Assignment				       */
/*  ================================== */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*Boolean*/
#define FALSE 0
#define TRUE !FALSE

//Declaring thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

//Declaring mutex
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
/*
* Struct serves as storage since we can only parse one pointer to threads
*/
typedef struct
{
	char buffer1[40];
	char buffer2[40];
	
} Buffers;

void *threadA(void *arg)
{	
	pthread_cond_init(&cond1, NULL);
	//Buffers *bf = (Buffers*) arg;
	pthread_mutex_lock(&lock1);

	printf("Thread A init...\n");		
	execl("../PP/PP", "PP", (char*) NULL); //CANNOT RUN AS THREAD AS IT REPLACES PROCESS
	pthread_cond_wait(&cond1, &lock1);
	// Start critical section
	//pthread_mutex_lock(&lock1);

	// End critical section
	pthread_mutex_unlock(&lock1);

	pthread_exit(NULL);
}

/*
* Thread B runs PP program
*/
void *threadB(void *arg)
{

	printf("Thread B init...\n");
	execl("../SRTF/SRTF", "SRTF", (char*) NULL); //runs SRTF sim
	pthread_cond_wait(&cond1, &lock1);
	
	pthread_exit(NULL);
}

int main(void)
{
	Buffers bf; //Struct used to store buffers
	pthread_cond_init(&cond1, NULL);
	pthread_t idA; //Thread ID's
	//pthread_t idB;
	
	//creates new threads(thread ID, thread attributes, function to run, arguments)
	pthread_create(&idA, NULL, threadA, &bf); //runs thread A
	//pthread_create(&idB, NULL, threadB, &bf); ////runs thread B

	printf("Enter a valid filename or QUIT\n");
	scanf("%s", bf.buffer1);
	//pthread_cond_signal(&cond1);

	//pthread_join(idA, NULL);
	
	//wait until threads work is done (id, parameter to return)
	
	//pthread_join(idB, NULL);
	
	return 0;
}


/*

	
//pthread_mutex_lock(&runB);
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
