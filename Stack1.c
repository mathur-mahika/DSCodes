#define<stdio.h>

#define maxLen 10

int count = 0;

struct stack{
    int items[maxLen];
    int top;
};

typedef struct stack st;

void createEmptyStack(struct stack* Node, int data)
{
    Node->top = -1;
}

int isFull(st* Node)
{
    if(Node->top == maxLen-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(st* Node)
{
    if(Node->top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* Node, int newItem)
{
    if(isFull(Node))
    {
        printf("FUUUULLLLLLLLLL");
    }
    else{
        Node->top++;
        Node->items[Node->top] = newItem;
    }
    count++; //to know how many items have been pushed into the stack
}

void pop(st* Node)
{
    if(isEmpty(Node))
    {
        printf("EMPTYYYYYYYYYYYY");
    }
    else
    {
        printf("%d", Node->items[Node->top]);
        //printf("Item popped = %d\n",  Node->items[Node->top]);
        Node->top--;
    }
}