#include "queue.h"

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmptyQueue(Queue *q) {
    return q->size == 0;
}

int isFullQueue(Queue *q) {
    return q->size == MAX_SIZE;
}

int enqueue(Queue *q, int value) {
    if (isFullQueue(q)) return 0;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
    return 1;
}

int dequeue(Queue *q, int *removedValue) {
    if (isEmptyQueue(q)) return 0;
    *removedValue = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return 1;
}

// ====================== STACK ======================
void initStack(MyStack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(MyStack *s, int value) {
    enqueue(&s->q1, value);        // O(1)
}

int pop(MyStack *s) {
    if (isEmptyQueue(&s->q1)) {
        printf("Stack underflow\n");
        return -1;
    }

    // Di chuyển n-1 phần tử từ q1 sang q2
    while (s->q1.size > 1) {
        int val;
        dequeue(&s->q1, &val);
        enqueue(&s->q2, val);
    }

    // Phần tử cuối cùng là top
    int top;
    dequeue(&s->q1, &top);

    // Swap q1 và q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return top;
}

int peek(MyStack *s) {
    if (isEmptyQueue(&s->q1)) {
        printf("Stack empty\n");
        return -1;
    }

    while (s->q1.size > 1) {
        int val;
        dequeue(&s->q1, &val);
        enqueue(&s->q2, val);
    }

    int top = s->q1.data[s->q1.front];
    enqueue(&s->q2, top);           // đẩy lại
    dequeue(&s->q1, &top);          // xóa khỏi q1

    // Swap
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return top;
}

int isEmptyStack(MyStack *s) {
    return isEmptyQueue(&s->q1);
}

int getSizeStack(MyStack *s) {
    return s->q1.size;
}

void displayStack(MyStack *s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (bottom -> top) [ ");

    // Tạo queue tạm để hiển thị mà không phá hủy stack
    Queue temp;
    initQueue(&temp);

    int val;
    while (dequeue(&s->q1, &val)) {
        printf("%d ", val);
        enqueue(&temp, val);
    }

    // Khôi phục lại q1
    while (dequeue(&temp, &val)) {
        enqueue(&s->q1, val);
    }

    printf("]\n");
}