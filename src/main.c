#include <stdio.h>
#include "stack.h" 
#define MAX 10

int main(void)
{
    Stack sk;
    initStack(&sk);
    int i;
    for (i = 0; i < MAX; i++)
        push(&sk, i);
    displayStack(sk);
    
    while (i-- > 0)
        printf("Poped: %i\n", pop(&sk));

    freeStack(&sk);
    return 0;
}
