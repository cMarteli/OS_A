
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
#include <ctype.h>

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

// Node
typedef struct node {
    int burst;
    char letter;
 
    // Lower values indicate higher priority
    int priority;
 
    struct node* next;
 
} Node;

//Methods
//main
void enter(char* filename);
void printInfo(Input* inp);
void menu();

//schedulers.c
void priority(Input* inp);
int compareArrival(const void *s1, const void *s2);
int comparePriority(const void *p1, const void *p2);
void addToReadyQ(Input* inp, Node** rq, int* ct);

//fileIO.c
void loadInput(char* filename, Input* inp);
Input processInput(char* filename);
int countLines(char* filename);

//header priorityQueue.c
Node* newNode(int d, int p, char l);
void pop(Node** head);
void push(Node** head, int b, int p, char l);
int isEmpty(Node** head);


#endif