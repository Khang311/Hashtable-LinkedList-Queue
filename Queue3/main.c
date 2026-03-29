#include "queue.h"

int main() 
{
    MyStack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    displayStack(&s);

    printf("Top: %d\n", peek(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Top sau pop: %d\n", peek(&s));
    printf("Size: %d\n", getSizeStack(&s));

    displayStack(&s);

    return 0;
}