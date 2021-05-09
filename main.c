/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: main.c                      */
/*   OS Assignment				       */
/*  ================================== */

#include "header.h"

/*!!!!!!!!!!!!!!!Has to be changed to take an array as parameter*/
/*
void priorityScheduler(Process p)
{
	printf("Burst Time: %d\nPriority: %d\nArrival Time: %d\n", p.burstTime, //
		p.priority, p.arrivalTime);

}
*/



int main()
{
	char* filename = "inputFile.txt";
	Input input;
	loadInput(filename, &input);
	printInfo(&input);
	return 0;
}


void printInfo(Input* inp)
{
	int i;
	printf("Total Processes:%d\n",inp->totalProcesses);
	for(i = 0; i < inp->totalProcesses; i++)
	{
		printf("A.T:%d\nB.T:%d\nPRIO:%d\n\n",
			inp->processes[i].arrivalTime,inp->processes[i].burstTime, inp->processes[i].priority);
	}
}