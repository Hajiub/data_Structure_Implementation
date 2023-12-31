#ifndef STACK_H
#define STACK_H
#include "lk.h"

typedef struct
{
    Node *head;
} Stack;

void initStack(Stack *sk);
void push(Stack *sk, int data);
int pop(Stack *sk);
void displayStack(Stack sk);
void freeStack(Stack *sk);
#endif


