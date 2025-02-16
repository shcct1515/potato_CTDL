#include<stdio.h>
#define max 100
typedef int elementtype;
typedef int position;
typedef struct 
{
    elementtype element[max];
    position last;
} list;

void makenull(list *l){
    l->last =0;
}

void insert(int x, position p, list* l){
    if (p>0 && p<= max && l->last<max)
    {
        for (int i = l->last-1; i >= p-1; i--)
        {
            l->element[i+1] = l->element[i];
        }
        l->element[p-1] = x;
        l->last++;
    } else if (p<=0)
    {
        printf("vi tri %d la khong hop le \n", p);
    }else if (l->last==max)
    {
        printf("danh sach da day");
    }
    
    
}

void del(position p, list* l){
    for (int i = p-1; i <= l->last-1; i++)
    {
        l->element[i] = l->element[i+1];
    }
    l->last--;
}

void print(list* l){
    printf("trong danh sach co %d phan tu: \n", l->last);
    for (int i = 0; i <= l->last-1; i++)
    {
        printf("%d ", l->element[i]);
    }
    
}

int main(){
    list l;
    makenull(&l);
    l.element[0] = 2;
    l.element[1] = 4;
    l.element[2] = 6;
    l.last = 3;
    insert(3, 4, &l);
    print(&l);
    return 0;
}