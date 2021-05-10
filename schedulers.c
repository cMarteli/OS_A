/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: fileio.c                    */
/*                                     */
/*  ================================== */
#include "header.h"

void priority(Input* inp)
{
	//sort
	qsort(inp->processes, inp->totalProcesses, sizeof(struct Process), comparePriority);

	//printf("Process %c has arrival time of %d\n",p.letter, p.arrivalTime);
  


}
/*
* Takes two processes, returns the one with earliest arrival time
* if the same returns first parameter
*/
struct Process compareArrival(struct Process p1, struct Process p2)
{
	if(p1.arrivalTime <= p2.arrivalTime)
	{
		return p1;
	}
	else
	{
		return p2;
	}


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


/*
int compare(const void *s1, const void *s2)
{
	struct Process *p1 = (struct Process *)s1;
	struct Process *p2 = (struct Process *)s2;
	int prioCompare = strcmp(p1->priority, p2->priority);
	/* if same priority sort by A.T */
/*	if (prioCompare == 0)
	{
    	return p1->arrivalTime - p2->arrivalTime;
	}
	else
	{
		return -prioCompare;  /* the minus puts "lower prio" first*/
/*	}

    
}
*/