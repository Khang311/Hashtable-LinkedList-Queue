#include "stack.h"

//1.
void init(Stack *s) 
{
    s->top1 = -1;
    s->top2 = MAX_SIZE;
}

int isEmpty1(const Stack *s) 
{ 
    return s->top1 == -1; 
}
int isEmpty2(const Stack *s) 
{ 
    return s->top2 == MAX_SIZE; 
}

int isFull1(const Stack *s) 
{ 
    return s->top1 + 1 == s->top2; 
}
int isFull2(const Stack *s) 
{ 
    return s->top1 + 1 == s->top2;
}

void push1(Stack *s, int value)
{
    if (isFull1(s)) {
        printf("Stack 1 overflow!\n");
        return;
    }
    s->data[++s->top1] = value;
}

void push2(Stack *s, int value)
{
    if (isFull2(s)) {
        printf("Stack 2 overflow!\n");
        return;
    }
    s->data[--s->top2] = value;
}

int pop1(Stack *s)
{
    if (isEmpty1(s)) {
        printf("Stack 1 underflow!\n");
        return -1;
    }
    return s->data[s->top1--];
}

int pop2(Stack *s)
{
    if (isEmpty2(s)) {
        printf("Stack 2 underflow!\n");
        return -1;
    }
    return s->data[s->top2++];
}

void display(const Stack *s)
{
    printf("Stack 1 (bottom -> top): [");
    for (int i = 0; i <= s->top1; i++) {
        printf("%d ", s->data[i]);
    }
    printf("]\n");

    printf("Stack 2 (bottom -> top): [");
    for (int i = MAX_SIZE-1; i >= s->top2; i--) {
        printf("%d ", s->data[i]);
    }
    printf("]\n");
}
