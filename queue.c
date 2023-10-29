#include <stdio.h>
#include <stdlib.h>
#define maxLen 10

int count = 0;

struct queue 
{
    int items[maxLen];
    int front, rear;
};

typedef struct queue q;

void createEmptyQueue(q* Node) 
{
    Node->front = -1;
    Node->rear = -1;
}

int isFull(q* Node) 
{
    if ((Node->rear == maxLen - 1 && Node->front == 0) || (Node->rear == Node->front - 1)) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int isEmpty(q* Node) 
{
    if (Node->front == -1) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

void enqueue(q* Node, int newItem) 
{
    if (isFull(Node)) 
    {
        printf("Queue is FULL!\n");
    } 
    else 
    {
        if (Node->front == -1) 
        {
            Node->front = 0;
        }

        Node->rear = (Node->rear + 1) % maxLen;
        Node->items[Node->rear] = newItem;
        count++; 
    }
}

int dequeue(q* Node) 
{
    int item;

    if (isEmpty(Node)) 
    {
        printf("EMPTYYYYYYY\n");
        return -1;
    } 
    else 
    {
        item = Node->items[Node->front];

        if (Node->front == Node->rear) 
        {
            Node->front = -1;
            Node->rear = -1;
        } 
        else 
        {
            Node->front = (Node->front + 1) % maxLen;
        }

        count--;
        return item;
    }
    /*
    IF(front == null)
    {
        PRINTF("UNDERFLOW");
        return -1;
    }
    else
    {
        struct queue* temp = front;
        int tempdata = front->data;
        free(temp);
        return tempdata;
    }
    */
}

void display(q* Node) 
{
    printf("QUEUE: \n");
    if (isEmpty(Node)) 
    {
        printf("Queue is EMPTY!\n");
    }
    else 
    {
        int i = Node->front;

        while (i != Node->rear) 
        {
            printf("%d\n", Node->items[i]);
            i = (i + 1) % maxLen;
        }

        printf("%d\n", Node->items[i]);
    }
    printf("\n");
    printf("Count value = %d\n", count);
}

int main() 
{
    struct queue* qe = (struct queue*)malloc(sizeof(struct queue));

    createEmptyQueue(qe);

    enqueue(qe, 1);
    enqueue(qe, 3);
    enqueue(qe, 5);
    enqueue(qe, 7);

    display(qe);

    int item = dequeue(qe);
    
    if (item != -1) 
    {
        printf("Dequeued items be like: %d\n", item);
    }

    printf("After dequeue: \n");
    display(qe);

    int choice;
    printd("Vhoode operation: ");
    printf("1: blah blah blah");

    return 0;
}