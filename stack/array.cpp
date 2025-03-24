#include<stdio.h>
#define max 100

typedef int elementtype;
typedef int position;
typedef struct 
{
    elementtype element[max];
    position top;
}stack;

void makenull(stack* s){
    s->top = 0;
}

void insert(elementtype x, stack* s){
    s->element[s->top] = x;
    s->top++;
}

void printstack(stack* s){
    for (int i = 0; i < s->top; i++)
    {
        printf("%d\n", s->element[i]);
    }
}

void delstack(stack* s){
    s->top--;
}

int main(){
    stack s;
    makenull(&s);
    insert(10, &s);
    insert(11, &s);
    insert(12, &s);
    insert(13, &s);
    printstack(&s);
    delstack(&s);
    delstack(&s);
    delstack(&s);
    printf("___________________\n");
    printstack(&s);
    return 0;
}