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
        for (int i = l->last-1; i > p; i--)
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

void insertuserinput(list* l){
    position p;
    elementtype x;
    printf("nhap gia tri va vi tri: ");
    scanf("%d %d", &x, &p);
    insert(x, p, l);
    printf("__________________________________________\n");
}

int main(){
    list l;
    makenull(&l);
    bool run = true;
    char c;
    while(run){
        insertuserinput(&l);
        print(&l);
        printf("ban muon nhap tiep ko (y/n): ");
        scanf("%c", &c);
        if (c == 'n')
        {
            run = false;
        }
    }
    return 0;
}