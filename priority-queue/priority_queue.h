#ifndef PRIORITY_QUEUE_H_INCLUDED
#define PRIORITY_QUEUE_H_INCLUDED

// Node type definition
typedef struct node {
    int data;       //further abbreviated as d
    int priority;   //further abbreviated as p
    struct node* next;

} Node;

Node* pq_Create(int ,int );
Node* pq_CreateEmpty();
void pq_Remove(Node**);
void pq_Insert(Node** , int, int );
int pq_IsEmpty(Node**);
void  pq_Join(Node**, Node*);

#endif // PRIORITY_QUEUE_H_INCLUDED
