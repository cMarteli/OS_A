/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: main.c                      */
/*   OS Assignment				       */
/*  ================================== */

#include "header.h"


int main()
{
	menu();


	return 0;
}

/*
* IMPORT: Board and Missile structs loaded with information from file
* Calls methods depending on user choice
*/
void menu()
{
	char userStr[11];
	int pass = FALSE;
	do
	{
		printf("PP simulation:\n");		
		scanf("%s", userStr);
		
			if(strcmp(userStr, "QUIT") == 0)
			{
				printf("****Goodbye!****\n");
				pass = TRUE;
			}

			else
			{
				//enter(userStr);
				enter("burst_list"); //delete HARDCODED
			}
	}while(pass != TRUE);
}

void enter(char* filename)
{

	Input input;
	loadInput(filename, &input);
	priority(&input);
}

void printInfo(Input* inp)
{
	int i;
	printf("Total Processes:%d\n",inp->totalProcesses);
	for(i = 0; i < inp->totalProcesses; i++)
	{
		printf("Symbol:%c\nA.T:%d\nB.T:%d\nPRIO:%d\n\n",
			inp->processes[i].letter, inp->processes[i].arrivalTime, inp->processes[i].burstTime, inp->processes[i].priority);
	}
}

/*Clears screen*/
void clrscr()
{
    system("cls||clear");
}