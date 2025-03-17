#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct node
{
    elementtype element;
    struct node* next;
} node;
typedef node* list;
typedef int position;

list makenull(){
    node* header = (node*)malloc(sizeof(node));
    header->next = NULL;
    return header;
}

void insertafterheader(elementtype x, list l){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element = x;
    newNode->next = l->next;
    l->next = newNode;
}

void insert(elementtype x, position p, list l){
    node* temp = l;
    if(temp->next == NULL){
        insertafterheader(x, l);
    } else{
        node* newNode = (node*)malloc(sizeof(node));
        for (int i = 1; i < p; i++)
        {
            temp = temp->next;
        }
        newNode->element = x;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printlist(list l){
    node* p = l->next;
    int point = 1;
    while (p !=NULL)
    {
        printf("vi tri %d: ", point);
        printf("%d \n", p->element);
        p = p->next;
        point++;
    }
    
}

void dellist(position p, list l){
    node* temp = l;
    for (int i = 1; i < p; i++)
    {
        temp = temp->next;
    }
    node* delnode = temp->next;
    temp->next = delnode->next;
    free(delnode);
}

int main(){
    list l = makenull();
    insertafterheader(11, l);
    insertafterheader(12, l);
    insertafterheader(13, l);
    insertafterheader(14, l);
    insert(9, 1, l);
    insert(10, 6, l);
    printlist(l);
    return 0;
}
