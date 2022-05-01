/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: schedulers.c                */
/*   OS Assignment                     */
/*  ================================== */
#include "header.h"

/*
* Starts PP scheduler draws gant and ticks clock forward
* IMPORT: inp(struct pointer)
*/
void priority(Input* inp)
{
	int currentTime = 0;
	double avgWaitTime = 0.0, avgTurnTime = 0.0;
	char currentProccess = ' ';
	int index = 0;
	int *waitingTime = (int*)malloc(sizeof(int)*inp->totalProcesses);

	//sorts input array by arrival time
	qsort(inp->processes, inp->totalProcesses, sizeof(struct Process), compareArrival);

	//initalise queue by loading first from array
	Node* rq = createNode(inp->processes[0].burstTime, inp->processes[0].priority, inp->processes[0].letter);
	currentProccess = inp->processes[0].letter;
	printf("| %c  ", currentProccess);

	//while queue has items proccess
	while (!isEmpty(&rq))
	{

		addToReadyQ(inp, &rq, &currentTime); //adds to ready queue

		if(currentProccess != rq->letter) //context switch
		{
			currentProccess = rq->letter;
			printf("|  %c  ", currentProccess);
			waitingTime[index] = currentTime;
			index++;
		}

		currentTime++; //clock tick
		rq->burst--; //decreases processing time by a clock tick


		if(rq->burst == 0) //if finished processing dequeue
		{
			dequeue(&rq);

		}

	}//END OF WHILE LOOP
	waitingTime[index] = currentTime;
	double temp = 0.0;
	printf("|\n0 ");
	for(int i = 0; i <= index; i++)
	{
		printf("%d ", waitingTime[i]);
		temp += (double)waitingTime[i]; //calculates average
	}
	temp = temp - waitingTime[index];//deletes last added value for avg
	avgWaitTime = temp /(index+1);
	avgTurnTime = getAvgBurst(inp) + avgWaitTime;

	printf("\nAverage waiting time: %0.2f\n", avgWaitTime);
	printf("Average turnaround time: %0.2f\n", avgTurnTime);

	free(waitingTime);

}

/*
* Adds any processes at current A.T to readyQueue
* IMPORT: inp(address of input array), [r]eady[q]ueue(struct pointer), [c]urrent[t]ime(int pointer)
*/
void addToReadyQ(Input* inp, Node** rq, int* ct)
{
	for(int i = 0; i < inp->totalProcesses; i++)
	{
		if(inp->processes[i].arrivalTime == *ct)
		{
			queue(rq, inp->processes[i].burstTime, inp->processes[i].priority, inp->processes[i].letter);
		}
	}

}

/*
* EXPORT: averageBurstTime(double)
* IMPORT: inp(address of input array), [r]eady[q]ueue(struct pointer), [c]urrent[t]ime(int pointer)
*/
double getAvgBurst(Input* inp)
{
	double temp = 0.0, avgBurst = 0.0;
	for(int i = 0; i < inp->totalProcesses; i++)
	{
		temp += inp->processes[i].burstTime;
	}
	avgBurst = temp/inp->totalProcesses;
	return avgBurst;
}

/*
* Takes two processes, returns the one with earliest arrival time
* if the same returns first parameter, used for sorting input array
*/
int compareArrival(const void *s1, const void *s2)
{
	struct Process *p1 = (struct Process *)s1;
	struct Process *p2 = (struct Process *)s2;
	int compare = p1->arrivalTime - p2->arrivalTime;
	if(compare == 0)
	{
		return(p1->priority - p2->priority);
	}
	else
	{
		return(p1->arrivalTime - p2->arrivalTime);
	}
}