#include <stdio.h>
#include "queue-linklist.h"

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    int x;

    peek(&q, &x);
    printf("Front: %d\n", x);

    dequeue(&q, &x);
    printf("Dequeued: %d\n", x);

    printf("Size: %d\n", size(&q));

    return 0;
}