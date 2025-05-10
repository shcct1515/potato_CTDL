//Binary Search Tree - BST)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int elementtype;

struct node {
    elementtype element;
    node *left;
    node *right;
};

typedef node* tree;

void makenull(tree *T) {
    (*T) = NULL;
}

tree left_tree(tree T) {
    return T->left;
}

tree right_tree(tree T) {
    return T->right;
}

void insert_tree(elementtype x, tree *T) {
    if ((*T) == NULL) {
        (*T) = (node*)malloc(sizeof(node));
        (*T)->element = x;
        (*T)->left = NULL;
        (*T)->right = NULL;
    } else {
        if (x < (*T)->element)
            insert_tree(x, &(*T)->left);
        else
            insert_tree(x, &(*T)->right);
    }
}

void tientu(tree T) {
    printf("%d ", T->element);
    if (T->left != NULL) tientu(T->left);
    if (T->right != NULL) tientu(T->right);
}

void trungtu(tree T) {
    if (T->left != NULL) trungtu(T->left);
    printf("%d ", T->element);
    if (T->right != NULL) trungtu(T->right);
}

void hautu(tree T) {
    if (T->left != NULL) hautu(T->left);
    if (T->right != NULL) hautu(T->right);
    printf("%d ", T->element);
}

int main() {
    tree T;
    makenull(&T);

    insert_tree(20, &T);
    insert_tree(12, &T);
    insert_tree(4, &T);
    insert_tree(27, &T);
    insert_tree(30, &T);
    insert_tree(34, &T);
    insert_tree(40, &T);
    insert_tree(50, &T);

    printf("duyet tien tu: ");
    tientu(T);
    printf("\n");

    printf("duyet trung tu: ");
    trungtu(T);
    printf("\n");

    printf("duyet hau tu: ");
    hautu(T);
    printf("\n");

    return 0;
}
