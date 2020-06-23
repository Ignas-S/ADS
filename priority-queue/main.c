#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

Node* pq_Create(int ,int );
Node* pq_CreateEmpty();
void pq_Remove(Node**);
void pq_Insert(Node** , int, int );
int pq_IsEmpty(Node**);
void  pq_Join(Node**, Node*);

int main(){

    Node* head = pq_Create(69, 68);
    pq_Insert(&head, 10, 12);
    pq_Insert(&head, 17, 151);
    pq_Insert(&head, 50, 155);

    Node* head2 = pq_Create(333, 222);
    pq_Insert(&head2, 1500, 120);
    pq_Insert(&head2, 8, 10000);
    pq_Insert(&head2, 8, 10000);

    pq_Join(&head, head2);

    pq_Remove(&head);
    pq_Remove(&head);

    Node* temp = head;
    while (!pq_IsEmpty(&temp)) {
        printf("%d      %d \n", temp->data, temp->priority);
        temp = temp->next;
    }
    return 0;
}
