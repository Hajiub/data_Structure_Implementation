#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "logger.h"


void initStack(Stack *sk)
{
    sk->head = NULL;
}

void push(Stack *sk, int data)
{
    Node *new_node = createNode(data);
    // push at the end
    if (!sk->head)
    {
        sk->head = new_node;
        return;
    }
    
    Node *current = sk->head;
    while (current->next)
        current = current->next;

    current->next = new_node;
}

int pop(Stack *sk)
{
    int data;
    Node *current = sk->head;
    if (!current)
    {
        logMessage(ERROR,"Error: stack is empty");
        return 0;
    }
    else if (!current->next)
    {
       data = current->data;
       free(current);
       sk->head = NULL;
    }
    else
    {
        Node *prev;
        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        data = current->data;
        free(current);
        prev->next = NULL;
    }
    return data;
}
void displayStack(Stack sk)
{
    Node *n = sk.head;
    logMessage(INFO,"Display Stack!");
    printf("Stack [");
    while (n)
    {
        printf("%i%s",n->data, (n->next)? ", ": "");
        n = n->next;
    }
    printf("]\n");
}
void freeStack(Stack *sk)
{
    Node *current, *temp;
    current = sk->head;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    sk->head = NULL;
}
