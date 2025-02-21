void insertafterhead(elementtype x, list l){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element = x;
    newNode->next = l->next;
    l->next = newNode;
}
