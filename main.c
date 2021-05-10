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
	menu();

	return 0;
}

/*
* IMPORT: Board and Missile structs loaded with information from file
* Calls methods depending on user choice
*/
void menu()
{
	char userStr[10];
	int pass = FALSE;
	do
	{
		printf("PP simulation:\n[ENTER] file name\n[QUIT]\n");		
		scanf("%s", userStr);
		
			if(strcmp(userStr, "ENTER") == 0)
			{
				enter();
			}

			else if(strcmp(userStr, "QUIT") == 0)
			{
				printf("****Goodbye!****\n");
				pass = TRUE;
			}

			else
			{
			printf("!!Command not found!!\n");
			}
	}while(pass != TRUE);
}

void enter()
{
	
	char* filename= "burst_list"; //delete HARDCODED
	

	//uncomment before submission!!!!
	//char filename[11] = " ";
	//printf("Please enter file name:\n");
	//scanf("%10s", fn);

	Input input;
	loadInput(filename, &input);
	
	printInfo(&input);
	printf("-------------------------------------------\n");
	priority(&input);
	printInfo(&input);

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