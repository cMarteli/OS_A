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
	int currentTime = 0, totalBurstTime = 0;
	double avgWaitTime = 0.0, avgTurnTime = 0.0;
	char currentProccess = ' ';
	int index = 0;
	int *waitingTime = (void*)malloc(sizeof(int)*inp->totalProcesses);

	//sorts input array by arrival time
	qsort(inp->processes, inp->totalProcesses, sizeof(struct Process), comparePriority);
	
	//initalise queue by checking arrival times
	Node* rq = newNode(inp->processes[0].burstTime, inp->processes[0].priority, inp->processes[0].letter);
	if(inp->processes[0].arrivalTime != currentTime)
	{
		int i = 0;
		while(inp->processes[i].arrivalTime != currentTime)
		{
			i++;			
		}
		Node* rq = newNode(inp->processes[i].burstTime, inp->processes[i].priority, inp->processes[i].letter);
		currentProccess = inp->processes[i].letter;
	}
	else
	{
		Node* rq = newNode(inp->processes[0].burstTime, inp->processes[0].priority, inp->processes[0].letter);
		currentProccess = inp->processes[0].letter;
	}

	printf("| %c  ", currentProccess);
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

		
		if(rq->burst == 0) //if finished processing pop from queue
		{
			pop(&rq);

		}

	}//END OF WHILE LOOP

	printf("|\n");
	for(int i = 0; i < index; i++)
	{
		printf("%d ", waitingTime[i]);
		avgWaitTime += (double)waitingTime[i]; //calculates average
	}
	avgWaitTime = (avgWaitTime /index);

	printf("\nAverage waiting time: %0.2f\n", avgWaitTime);

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
			push(rq, inp->processes[i].burstTime, inp->processes[i].priority, inp->processes[i].letter);
		}
	}

}

/*
* Takes two processes, returns the one with earliest arrival time
* if the same returns first parameter, used for sorting input array
*/
int compareArrival(const void *s1, const void *s2)
{
	struct Process *p1 = (struct Process *)s1;
	struct Process *p2 = (struct Process *)s2;
	return(p1->arrivalTime - p2->arrivalTime);

}
/*
* Takes two processes, returns the one with highest priority (lowest number)
* if the same returns first parameter, used for sorting input array
*/
int comparePriority(const void *s1, const void *s2)
{
	struct Process *p1 = (struct Process *)s1;
	struct Process *p2 = (struct Process *)s2;
	int prioCompare = p1->priority - p2->priority;
	if(prioCompare == 0)
	{
		return(p1->arrivalTime - p2->arrivalTime);
	}
	else
	{
		return(p1->priority - p2->priority);	
	}
	
}