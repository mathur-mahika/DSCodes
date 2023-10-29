#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode{
    struct TreeNode* data;
    struct StackNode* next;
};

struct Stack{
    struct StackNode* top;
};

struct TreeNode* createNode(int data) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int data) 
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

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, struct TreeNode* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

struct TreeNode* pop(struct Stack* stack) {
    if (stack->top == NULL)
        return NULL;
    struct TreeNode* data = stack->top->data;
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void inorderTraversal_recur(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorderTraversal_recur(root->left);
    printf("%d ", root->data);
    inorderTraversal_recur(root->right);
}

void preorderTraversal_recur(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal_recur(root->left);
    preorderTraversal_recur(root->right);
}

void postorderTraversal_recur(struct TreeNode* root) {
    if (root == NULL)
        return;

    postorderTraversal_recur(root->left);
    postorderTraversal_recur(root->right);
    printf("%d ", root->data);
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
    {
        return;
    }

    struct Stack* stack = createStack();
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }

    free(stack);
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack();
    push(stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* current = pop(stack);
        printf("%d ", current->data);

        if (current->right != NULL)
            push(stack, current->right);

        if (current->left != NULL)
            push(stack, current->left);
    }

    free(stack);
}

int main() {

    struct TreeNode *head = NULL;
    int num, data, i=0;

    printf("Enter number of nodes to be created: ");
    scanf("%d", &num);

    printf("\nEnter data for %d nodes: \n", num);
    for(i = 0; i < num; i++)
    {
        scanf("%d", &data);
        head = insertNode(head, data);
    }

    printf("Inorder traversal: ");
    inorderTraversal(head);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(head);
    printf("\n");

    printf("Inorder traversal, Recursive: ");
    inorderTraversal_recur(head);
    printf("\n");

    printf("Preorder traversal, Recursive: ");
    preorderTraversal_recur(head);
    printf("\n");

    printf("Postorder traversal, Recursive: ");
    postorderTraversal_recur(head);
    printf("\n");

    return 0;
}
