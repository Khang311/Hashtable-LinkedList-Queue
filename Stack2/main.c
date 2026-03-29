#include <stdio.h>
#include "stack.h"


int main() {
    MinStack s;
    initMinStack(&s);

    pushMin(&s, 10);
    pushMin(&s, 20);
    pushMin(&s, 30);

    display(&s);

    printf("Top = %d, Min = %d\n", topMin(&s), getMin(&s));
    printf("Min = %d\n", getMin(&s));

    printf("Pop: %d\n", popMin(&s));
    printf("Min = %d\n", getMin(&s));
    display(&s);

    printf("Pop: %d\n", popMin(&s));
    printf("Min = %d\n", getMin(&s));
    
    display(&s);
    return 0;
}