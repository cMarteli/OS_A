/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: shortestFirst.c             */
/*   OS Assignment                     */
/*  ================================== */
#include "header.h"
 
/*
* Creates new readyQeue by creating head node also holds letter for PID
* IMPORT: [b]urst(integer), [p]riority(integer), [l]etter(char)
*/
Node* createNode(int b, char l)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->burst = b;
    head->letter = l;
    head->next = NULL;
 
    return head;
}
 
/*
* Removes element at head of list
* IMPORT: head(struct pointer)
*/
void dequeue(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
/*
* Queue according to priority in this case priority is shortest burst
* IMPORT: [b]urst(integer), [l]etter(char)
*/
void queue(Node** head, int b, char l)
{
    Node* start = (*head); 
    Node* temp = createNode(b, l);

    // If new head of has lesser burst we insert new node before head.
    if ((*head)->burst > b) 
    { 
        temp->next = *head;
        (*head) = temp;
    }
    else 
    { 
        // Goes through list and finds position to insert node
        while (start->next != NULL && start->next->burst < b) 
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