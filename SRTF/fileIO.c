/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: fileio.c                    */
/*   OS Assignment                     */
/*  ================================== */
#include "header.h"
/*
*IMPORT: String filenameB (filename)
*EXPORT: Board struct 
*checks then loads command line files, returns true if load is successful
*/
void loadInput(char* filename, Input* inp)
{


	FILE* fp = fopen(filename, "r");
	if(fp == NULL) /*checks if file exists*/
	{
		perror(filename);
	}
	else
	{	
		*inp = processInput(filename); /*processes any file and returns it as a struct*/
		printf("Loaded File: %s\n",filename);
		
	}
	fclose(fp);		
}

/*NEED TO ADD ALL METHODS*/
Input processInput(char* filename)
{
	Input inp;
	FILE* fp = fopen(filename, "r");
	int i, lineNum;
	char symbol = 'A';

	lineNum = countLines(filename);
	inp.totalProcesses = lineNum; /*gets number of processes on file by counting the lines*/

	for(i = 0; i < lineNum; i++) /*loads rest of file into struct*/
	{
		fscanf(fp,"%d %d", \
			&inp.processes[i].arrivalTime, &inp.processes[i].burstTime);
		/*assigns process a letter for gant*/
		inp.processes[i].letter = symbol;
		symbol++;
	}
	fclose(fp);
	return inp;
}

/*
* Import: filename (string)
* Export: Num of lines in file (int)
* Gets number of lines in file 
* PS. filename must be parsed here because scanf changes location of file pointer
*/
int countLines(char* filename)
{
	int count = 1;
	char chr;
	FILE* ptr = fopen(filename, "r");
    chr = getc(ptr);
    while (chr != EOF) /* counts newlines until end of file*/
    {
        if (chr == '\n')
        {
            count++;
        }
        chr = getc(ptr);
    }
	fclose(ptr);
    return count;
}