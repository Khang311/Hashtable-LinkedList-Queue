#include "queue-linklist.h"

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

int size(Queue *q)
{
    return q->count;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->count++;
}

int dequeue(Queue *q, int *value)
{
    if (isEmpty(q))
        return 0;

    Node *temp = q->front;
    *value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->count--;

    return 1;
}

int peek(Queue *q, int *frontValue)
{
    if (isEmpty(q))
    {
        return 0;
    }
    *frontValue = q->front->data;
    return 1;
}