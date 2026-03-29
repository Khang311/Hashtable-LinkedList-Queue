#ifndef QUEUE_LINKLIST_H
#define QUEUE_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int count;
} Queue;

void initQueue(Queue *q);
int size(Queue *q);  
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q, int *value);
int peek(Queue *q, int *frontValue);

#endif