#include "stack.h"

void initMinStack(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}

int isEmptyMin(const MinStack *s) {
    return s->top == -1;
}

void pushMin(MinStack *s, int x) {
    if (s->top == MAX_SIZE - 1) {
        printf("MinStack overflow!\n");
        return;
    }

    s->mainStack[++s->top] = x;

    if (s->minTop == -1 || x <= s->minStack[s->minTop]) {
        s->minStack[++s->minTop] = x;
    }
}

int popMin(MinStack *s) {
    if (isEmptyMin(s)) {
        printf("MinStack underflow!\n");
        return 0;
    }

    int val = s->mainStack[s->top--];

    if (s->minTop >= 0 && val == s->minStack[s->minTop]) {
        s->minTop--;
    }

    return val;
}

int topMin(const MinStack *s) {
    if (isEmptyMin(s)) {
        printf("Stack is empty!\n");
        return 0;
    }
    return s->mainStack[s->top];
}

int getMin(const MinStack *s) {
    if (s->minTop == -1) {
        printf("Stack is empty!\n");
        return 0;
    }
    return s->minStack[s->minTop];
}

void display(MinStack *s)
{
    if (isEmptyMin(s))
    {
        printf("Stack empty");
        return;
    }
    
    printf("Stack (bottom -> top) [");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->mainStack[i]);
    }
    printf("]\n");
}