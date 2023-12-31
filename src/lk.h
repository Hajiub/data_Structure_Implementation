#ifndef LK_H
#define LK_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

void initList(List *ls);
void freeList(List *ls);
Node *createNode(int data);
void insertAtBeginning(List *ls, int data);
void insertAtEnd(List *ls, int data);
void insertAtPosition(List *ls,int position, int data);
int deleteAtBeginning(List *ls);
int deleteAtend(List *ls);
int deleteAtPosition(List *ls, int position);
void display(List ls);
int getLength(List ls);
void reverse(List *ls);
int isEmpty(List ls);
#endif
