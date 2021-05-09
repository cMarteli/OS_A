
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



//fileIO.c
void loadInput(char* filename, Input* inp);
Input processInput(char* filename);
int countLines(char* filename);


#endif