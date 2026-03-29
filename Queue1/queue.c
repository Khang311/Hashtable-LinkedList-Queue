#include <stdio.h>
#include "queue.h"

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size =0;
}

int isEmpty(Queue *q)
{
    return q->size == 0;
}

int isFull(Queue *q)
{
    return q->size == MAX_SIZE;
}

int enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        return 0;
    }
    q->rear = (q->rear +1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;

    return 1;
}

int dequeue(Queue *q, int *removedValue)
{
    if (isEmpty(q))
    {
        return 0;
    }
    *removedValue = q->data[q->front];
    q->front = (q->front +1) % MAX_SIZE;
    q->size--;
    return 1;
}

int peek(Queue *q, int *frontValue)
{
    if (isEmpty(q))
    {
        return 0;
    }
    *frontValue = q->data[q->front];
    return 1;
}


void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
        return;
    }

    printf("Queue (front -> rear) [");
    int index = q->front;
    for (int i = 0; i < q->size; i++)
    {
        printf("%d ", q->data[index]);
        index = (index +1) % MAX_SIZE;
    }
    printf("]\n");
}

void reverse(Queue *q, int K)
{
    if (K <= 0 || K > q->size || isEmpty(q))
        return;

    for (int i = 0; i < K / 2; i++)
    {
        int left = (q->front + i) % MAX_SIZE;
        int right = (q->front + K - 1 - i) % MAX_SIZE;

        int temp = q->data[left];
        q->data[left] = q->data[right];
        q->data[right] = temp;
    }
}