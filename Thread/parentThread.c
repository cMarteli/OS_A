/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: main.c                      */
/*   OS Assignment				       */
/*  ================================== */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *entry_point(void *value)
{
	printf("hello from the second thread :)\n");

	int *num = (int *) value;
	printf("The value of num is %d\n", *num);

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thread;

	printf("Hello from the first thread :D\n");

	int num = 123;

	pthread_create(&thread, NULL, entry_point, &num);

	pthread_join(thread, NULL);

	//int threadA = system("../PP/./PP");
	//int threadB = system("../SRTF/./SRTF");
	return EXIT_SUCCESS;
}
