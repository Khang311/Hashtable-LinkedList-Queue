#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;
    init(&s);

    push1(&s, 10);
    push1(&s, 20);
    push1(&s, 30);

    push2(&s, 11);
    push2(&s, 22);
    push2(&s, 33);

    display(&s);

    printf("Pop1: %d\n", pop1(&s));
    printf("Pop2: %d\n", pop2(&s));

    display(&s);

    return 0;
}