#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int mainStack[MAX_SIZE];
    int minStack[MAX_SIZE];
    int top;
    int minTop;
} MinStack;

void initMinStack(MinStack *s);
void pushMin(MinStack *s, int x);
int popMin(MinStack *s);
int topMin(const MinStack *s);
int getMin(const MinStack *s);
int isEmptyMin(const MinStack *s);
void display(MinStack *s);
#endif