#include <stdlib.h>
#include "lk.h"
#include "logger.h"

void initList(List *ls)
{
    ls->head = NULL;
}
void freeList(List *ls)
{
    Node *current, *temp;
    current = ls->head;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
}

Node *createNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        logMessage(ERROR, "Couldn't Allocate enough Memory!");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertAtBeginning(List *ls, int data)
{
    Node *new_node = createNode(data);
    new_node->next = ls->head;
    ls->head = new_node;
    logMessage(INFO, "%i Inserted at the beginning", data);
}

void insertAtEnd(List *ls, int data)
{
    Node *new_node = createNode(data);
    if (ls->head == NULL)
    {
        ls->head = new_node;
        return;
    }

    Node *current = ls->head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new_node;
}

void insertAtPosition(List *ls,int position, int data)
{
    if (position < 0)
    {
        logMessage(ERROR, "Invalid position!");
        return;
    }

    Node *new_node = createNode(data);

    if (position == 0)
    {
        new_node->next = ls->head;
        ls->head = new_node;
    }
    else
    {
        int count = 1;
        Node *current = ls->head;
        Node *prev = NULL;
        while (current && count < position)
        {
            prev = current;
            current = current->next;
            count++;
        }

        if (!current)
        {
            prev->next = new_node;
            return;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
}

int deleteAtBeginning(List *ls)
{
    if (isEmpty(*ls))
    {
        logMessage(ERROR, "IndexError: Delete From empty list!");
    }
    
    Node *n  = ls->head;
    int data = n->data;
    ls->head = n->next;
    free(n);

    return data;
}

int deleteAtend(List *ls) 
{
    if (isEmpty(*ls)) {
        logMessage(ERROR, "IndexError: Delete from empty list!");
        return NULL;
    }

    Node *current = ls->head;
    Node *prev = NULL;
    int data;
    if (!current->next) 
    {
        int data = current->data;
        free(current);
        ls->head = NULL;
        return data;
    }
    else
    {
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


int deleteAtPosition(List *ls, int position)
{
    if (isEmpty(*ls))
    {
        logMessage(ERROR, "IndexError: Delete from an empty list!");
        return NULL;
    }
    else if (position == 0)
    {
        return deleteAtBeginning(ls);
    }

    Node *current = ls->head;
    Node *prev = NULL;
    int count = 0;

    while (current && count < position)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (!current)
    {
        logMessage(ERROR, "IndexError: Position out of bounds");
        return NULL;
    }

    int data = current->data;

    if (current->next)
    {
        prev->next = current->next;
    } 
    else
    {
        prev->next = NULL;
    }

    free(current);
    return data;
}

void display(List ls)
{
    Node *current = ls.head;
    logMessage(INFO,"Display list");
    fprintf(stdout,"List: [");
    while (current)
    {
        fprintf(stdout, "%i%s", current->data, (current->next) ? ", ": "");
        current = current->next;
    }
    fprintf(stdout,"]\n");
}

int getLength(List ls)
{
    int count = 0;
    if(isEmpty(ls))
    {
        logMessage(INFO, "List is empty!");
    } 
    else
    {
        Node *current = ls.head;
        while (current)
        {
             current = current->next;
             count++;
        }
    }
    return count;
}

int isEmpty(List ls)
{
    // IF IT'S EMPTY RETURN 1 OTHER WISE 0 
    return (ls.head) ? 0 : 1; 
}



void reverse(List *ls)
{
    Node *current, *next, *prev;
    current = ls->head;
    next = NULL;
    prev = NULL;
    
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    ls->head = prev;
}
