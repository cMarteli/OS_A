/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: priorityQueue.c             */
/*   OS Assignment                     */
/*  ================================== */
#include "header.h"
 
/*
* Creates new readyQeue by creating head node also holds letter for PID
* IMPORT: [b]urst(integer), [p]riority(integer), [l]etter(char)
*/
Node* newNode(int d, int p, char l)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->burst = d;
    temp->priority = p;
    temp->letter = l;
    temp->next = NULL;
 
    return temp;
}
 
/*
* Removes element at head of list
* IMPORT: head(struct pointer)
*/
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
/*
* Function to push according to priority
* IMPORT: [b]urst(integer), [p]riority(integer), [l]etter(char)
*/
void push(Node** head, int b, int p, char l)
{
    Node* start = (*head); 
    Node* temp = newNode(b, p, l);

    // If new head of has lesser priority we insert new node before head.
    if ((*head)->priority > p) 
    { 
        temp->next = *head;
        (*head) = temp;
    }
    else 
    { 
        // Goes through list and finds position to insert node
        while (start->next != NULL && start->next->priority < p) 
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}
 
/*
* Checks if list is empty
* IMPORT: head(struct pointer)
* EXPORT: boolean(int)
*/
int isEmpty(Node** head)
{
    return (*head) == NULL;
}