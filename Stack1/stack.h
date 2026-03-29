#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top1;
    int top2;
} Stack;

void init(Stack *s);
int isEmpty1(const Stack *s);
int isEmpty2(const Stack *s);
int isFull1(const Stack *s);
int isFull2(const Stack *s);
void push1(Stack *s, int value);
void push2(Stack *s, int value);
int pop1(Stack *s);
int pop2(Stack *s);
void display(const Stack *s);

#endif