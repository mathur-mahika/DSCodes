#include <stdio.h> 
#include <stdlib.h>
#define len 20

int count = 0;

struct Stack{
    int items[len];
    int top;
};

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int data) 
{
    struct Node *n;  
    n = (struct Node *)malloc(sizeof(struct Node));  
    n->data = data;  

    n->left = NULL;  
    n->right = NULL;

    return n;
}

struct Node* insertNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data);
    }

    if (data < root->data) 
    {
        root->left = insertNode(root->left, data);
    }
     else if (data > root->data) 
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void in_order(struct Node *root) 
{
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }    
}

int main () 
{
    struct Node *head = NULL;
    int num, data, i=0;

    printf("Enter number of nodes to be created: ");
    scanf("%d", &num);

    printf("\nEnter data for %d nodes: \n", num);
    for(i = 0; i < num; i++)
    {
        scanf("%d", &data);
        head = insertNode(head, data);
    }

    printf("\n");
    printf("Inorder traversal: ");
    in_order(head);

    return 0;
}