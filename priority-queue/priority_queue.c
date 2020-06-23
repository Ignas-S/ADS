#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
// Nomenclature - every function starts with pq_ (priority queue) into function name with first letters capitalized

// Node type definition
typedef struct node {
    int data;       //further abbreviated as d
    int priority;   //further abbreviated as p
    struct node* next;

} Node;

// Joins two priority lists into the first one
void  pq_Join(Node** head1, Node* head2)
{
    while(head2 != NULL)
    {
        Node* temp = head2;
        head2 = head2->next;
        pq_Insert(head1, temp->data, temp->priority);
        free(temp);
    }
}


// Function - creates a new node, receives - d (data), p (priority), returns node address
Node* pq_Create(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Remove the element with the highest priority
void pq_Remove(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

// Function to insert an element
void pq_Insert(Node** head, int d, int p)
{
    // start - beginning of the list
    Node* start = (*head);
    // temp - the insertor node
    Node* temp = pq_Create(d, p);

    // If the insertor node has a higher priority than the head node, it pushes the head node back
    if ((*head)->priority < p) {
        temp->next = *head;
        (*head) = temp;
    }
    else {

        // If the next element has a higher priority, move on to the next
        // Arrive either between two elements or at the end of the list
        while (start->next != NULL && (start->next)->priority >= p) {
            start = start->next;
        }
        // The element after the insertor is the one following our current position in the list (or NULL)
        temp->next = start->next;
        // The element preceding the insertor is the one we're currently at
        start->next = temp;
    }
}

// Checks if the given Node* pointer is pointing to a NULL value, functionally valueless
int pq_IsEmpty(Node** head)
{
    return (*head) == NULL ;
}

//Creates an empty node, functionally useless
Node* pq_CreateEmpty()
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;

    return temp;
}


