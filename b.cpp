#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct node
{
    elementtype element;
    struct node* next;
} node;
typedef node* list;

list makenull(){
    list header = (node*)malloc(sizeof(node));
    header->next = NULL;
    return header;
}

void insertafterheader(elementtype x, list l){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element = x;
    newNode->next = l->next;
    l->next = newNode;
}

void printlist(list l){
    node* p = l->next;
    while (p != NULL)
    {
        printf("%d ", p->element);
        p = p->next;
    }
    
}

int main(){
    list l = makenull();
    insertafterheader(10, l);
    insertafterheader(11, l);
    insertafterheader(12, l);
    printlist(l);
    return 0;
}