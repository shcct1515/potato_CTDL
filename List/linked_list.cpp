#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
struct node
{
    elementtype element;
    node* next;
};
typedef node* position;
typedef position list;

void makenull(list* l){
    (*l) = (node*)malloc(sizeof(node));
    (*l)->next = NULL;
}

void insert(elementtype x, position p){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->element =x;
    newnode->next = p->next;
    p->next = newnode;
}

void nhapds(list l){
    elementtype x, p;
    position temp = l;
    printf("nhap gia tri: ");
    scanf("%d", &x);
    printf("nhap vi tri: ");
    scanf("%d", &p);
    for (int i = 1; i < p; i++)
    {
        temp = temp->next;
    }
    insert(x, temp);
}

void dellist(position p){
    node* delnode = p->next;
    p->next = delnode->next;
    free(delnode);
}

void xoads(list l){
    elementtype p;
    position temp = l;
    printf("nhap vi tri can xoa: ");
    scanf("%d", &p);
    for (int i = 1; i < p; i++)
    {
        temp = temp->next;
    }
    dellist(temp);
}

void printlist(list l){
    node* temp = l->next;
    while (temp != NULL)
    {
        printf("%d ", temp->element);
        temp = temp->next;
    }
    
}

int main(){
    list l;
    makenull(&l);
    nhapds(l);
    nhapds(l);
    nhapds(l);
    xoads(l);
    printlist(l);
    return 0;
}