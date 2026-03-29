#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H

#include <stdio.h>

#define MAX_SIZE 100

typedef struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

typedef struct MyStack {
    Queue q1;
    Queue q2;
} MyStack;

// Khởi tạo
void initStack(MyStack *s);
void initQueue(Queue *q);        // dùng chung

// Stack operations
void push(MyStack *s, int value);
int pop(MyStack *s);
int peek(MyStack *s);
int isEmptyStack(MyStack *s);
int getSizeStack(MyStack *s);
void displayStack(MyStack *s);

#endif