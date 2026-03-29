#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Initial Queue: ");
    displayQueue(&q);

    reverse(&q,4);
    printf("Queue Reverse: ");
    displayQueue(&q);


    int removed;
    if (dequeue(&q, &removed))
    {
        printf("Dequeued: %d\n", removed);
    }

    printf("Queue after dequeue: ");
    displayQueue(&q);

    int frontValue;
    if (peek(&q, &frontValue))
    {
        printf("Peek: %d\n", frontValue);
    }

    return 0;
}
