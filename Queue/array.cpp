#include<stdio.h>
#define max 30

typedef int elementtype;
typedef int position;
typedef struct {
    elementtype element[max];
    position front;
    position rear;
} queue;

void makenull(queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isfull(queue q) {
    return (q.rear - q.front + 1) == max;
}

int isempty(queue q) {
    return q.rear == -1;
}

void insert(elementtype x, queue* q) {
    if (isfull(*q)) {
        printf("hang doi day\n");
        return;
    }
    if (q->rear == max - 1) {
        for (int i = q->front; i <= q->rear; i++) {
            q->element[i - q->front] = q->element[i];
        }
        q->rear = q->rear - q->front;
        q->front = 0;
    }
    if (isempty(*q)) {
        q->rear++;
        q->element[q->rear] = x;
        q->front = q->rear;
    } else {
        q->element[q->rear + 1] = x;
        q->rear++;
    }
}

void delqueue(queue* q){
    q->front++;
}

void printqueue(queue q) {
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.element[i]);
    }
    printf("\n");
}

int main() {
    queue q;
    makenull(&q);
    insert(10, &q);
    insert(11, &q);
    insert(12, &q);
    insert(13, &q);
    delqueue(&q);
    printqueue(q);
    return 0;
}