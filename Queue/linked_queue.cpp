#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct node {
    elementtype element;
    struct node* next;
} node;

typedef node* position;
typedef position queue;

void makenullqueue(queue* q) {
    *q = (node*)malloc(sizeof(node));
    (*q)->next = NULL;
}

void insert(elementtype x, queue* q) {
    position p = *q;
    while (p->next != NULL) {
        p = p->next;
    }
    position newnode = (node*)malloc(sizeof(node));
    newnode->element = x;
    newnode->next = NULL;
    p->next = newnode;
}

void delqueue(queue* q) {
    position p = *q;
    position delnode = p->next;
    if (delnode != NULL) {
        p->next = delnode->next;
        free(delnode);
    }
}

void printqueue(queue q) {
    position p = q->next;
    while (p != NULL) {
        printf("%d ", p->element);
        p = p->next;
    }
    printf("\n");
}

int main() {
    queue q;
    makenullqueue(&q);
    insert(10, &q);
    insert(20, &q);
    insert(30, &q);
    printqueue(q);
    delqueue(&q);
    printqueue(q);
    return 0;
}
