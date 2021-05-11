/*  ================================== */
/*   Author: Caio Marteli              */
/*   Student ID: 19598552              */
/*   Name: priorityQueue.c             */
/*                                     */
/*  ================================== */
#include "header.h"

 
// Function to Create A New Node PARAMS burst time and priority
Node* newNode(int d, int p, char l)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->burst = d;
    temp->priority = p;
    temp->letter = l;
    temp->next = NULL;
 
    return temp;
}
 
// Return the value at head
int peek(Node** head)
{
    return (*head)->burst;
}
 
// Removes the element with the
// highest priority form the list
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
// Function to push according to priority
//d= burst, p = priority
void push(Node** head, int b, int p, char l)
{
    Node* start = (*head);
 
    // Create new Node
    Node* temp = newNode(b, p, l);
 
    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority > p) {
 
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {
 
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
            start->next->priority < p) {
            start = start->next;
        }
 
        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}
 
// Function to check is list is empty
int isEmpty(Node** head)
{
    return (*head) == NULL;
}