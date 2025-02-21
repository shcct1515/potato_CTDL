#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct
{
    elementtype element;
    node* next;
}node;
typedef node* list;
typedef list position;

list makenull(){
    list head = (node*)malloc(sizeof(node));
    head = NULL;
    head->next = NULL;
}

list insertafterhead(elementtype x, list l){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element = x;
    newNode->next = l->next;
    l->next = newNode;

}

int main(){
    list l = makenull();
    
    return 0;
}