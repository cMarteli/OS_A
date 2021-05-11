/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: fileio.c                    */
/*                                     */
/*  ================================== */
#include "header.h"

void priority(Input* inp)
{
	int currentTime = 0, totalBurstTime = 0;
	//sorting
	qsort(inp->processes, inp->totalProcesses, sizeof(struct Process), compareArrival);

	//create ready queue with first element on list
	Node* rq = newNode(inp->processes[0].burstTime, inp->processes[0].priority, inp->processes[0].letter);
	for(int i = 1; i < inp->totalProcesses; i++)
	{
		if(inp->processes[i].arrivalTime == currentTime)
		{
			push(&rq, inp->processes[i].burstTime, inp->processes[i].priority, inp->processes[i].letter);
		}
	}
	//clock tick
	while (!isEmpty(&rq)) {
	printf("%c:%d|", rq->letter, rq->burst);
	currentTime++; //clock tick
	rq->burst--; //decreases processing time by a clock tick
	addToReadyQ(inp, rq, &currentTime); //adds to ready queue
		if(rq->burst == 0) //if finished processing pop from queue
		{
			pop(&rq);
		}
	}
	printf("\n");

}
//inp = address of input array, rq = address of ready Q, ct= current time
void addToReadyQ(Input* inp, Node* rq, int* ct)
{
	//ct++; //advances time by 1
	//adds any processes at current A.T to readyQueue
	for(int i = 0; i < inp->totalProcesses; i++)
	{
		if(inp->processes[i].arrivalTime == *ct)
		{
			push(&rq, inp->processes[i].burstTime, inp->processes[i].priority, inp->processes[i].letter);
		}
	}

}

void draw()
{

}



/*
* Takes two processes, returns the one with earliest arrival time
* if the same returns first parameter
*/
int compareArrival(const void *s1, const void *s2)
{
	struct Process *p1 = (struct Process *)s1;
	struct Process *p2 = (struct Process *)s2;
	return(p1->arrivalTime - p2->arrivalTime);

}
/*
* Takes two processes, returns the one with highest priority (lowest number)
* if the same returns first parameter
*/
int comparePriority(const void *s1, const void *s2)
{
	struct Process *p1 = (struct Process *)s1;
	struct Process *p2 = (struct Process *)s2;
	return(p1->priority - p2->priority);
}