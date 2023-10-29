#include <stdio.h> 
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * create_node(int data) {
    
    struct Node *n;  

    n = (struct Node *)malloc(sizeof(struct Node));  

    n->data = data;  

    n->left = NULL;  
    n->right = NULL;

    return n;
}

int main() {
    
    struct Node *head = create_node(2);
    
    struct Node *a = create_node(1);
    struct Node *b = create_node(4);

    struct Node *c = create_node(11);
    struct Node *d = create_node(12);

    struct Node *e = create_node(3);

    head->left = a;
    head->right = b;

    a->left = c;
    a->right = d;

    b->left = NULL;
    b->right = e;


    return 0;
}

