#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct node
{
    elementtype element;
    struct node* next;
}node;
typedef node* list;
typedef list position;

list makenull(){
    list head = (node*)malloc(sizeof(node));
    head->next = NULL;
    return head;
}

void insertafterhead(elementtype x, list l){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element = x;
    newNode->next = l->next;
    l->next = newNode;
}

void printList(list l) {
    node* p = l->next;
    while (p != NULL) {
        printf("%d -> ", p->element);
        p = p->next;
    }
}

int main(){
    list l = makenull();
    insertafterhead(10, l);
    insertafterhead(12, l);
    insertafterhead(13, l);
    printList(l);
    return 0;
}