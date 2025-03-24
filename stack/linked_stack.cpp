#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct node
{
    elementtype element;
    node* next;
}stack;
typedef node* position;

void makenull(stack* s){
    s = (node*)malloc(sizeof(node));
    s->next = NULL;
}

position last(stack* s){
    position p = s;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    return p;
}

void insert(elementtype x, stack *s){
    node* newnode = (node*)malloc(sizeof(node));
    position p = last(s);
    newnode->element = x;
    newnode->next = p->next;
    p->next = newnode;
}

void delstack(stack* s){
    position p = s;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    node* delnode = p->next;
    p->next = delnode->next;
    free(delnode);
}

void printstack(stack* s){
    node* temp = s->next;
    while (temp != NULL)
    {
        printf("%d\n", temp->element);
        temp = temp->next;
    }
    
}

int main(){
    stack s;
    makenull(&s);
    insert(10, &s);
    insert(11, &s);
    insert(12, &s);
    insert(13, &s);
    delstack(&s);
    printstack(&s);
    return 0;
}