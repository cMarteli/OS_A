
/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: header.h                    */
/*   Part of OS Assignment Program     */
/*  ================================== */
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Boolean*/
#define FALSE 0
#define TRUE !FALSE

/*constants*/

#define MAX_SIZE 30 /*Max number of processes*/

/*
* Structs
*/
struct Process
{
	int arrivalTime, burstTime, priority; /*all integers*/
	char letter;
	
};
typedef struct
{
	int totalProcesses; /*all integers*/
	struct Process processes[MAX_SIZE]; /*Array of processes*/
	
} Input;

//Methods
//main

//void priorityScheduler();
void printInfo(Input* inp);

//schedulers.c
void priority(Input* inp);
struct Process compareArrival(struct Process p1, struct Process p2);
int comparePriority(const void *p1, const void *p2);
//int compare(struct Process* s1, struct Process* s2);

//fileIO.c
void loadInput(char* filename, Input* inp);
Input processInput(char* filename);
int countLines(char* filename);


#endif