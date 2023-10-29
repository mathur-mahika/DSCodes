#include <stdio.h>
#include <stdlib.h>

int choice(void)
{
    int ch;
    printf("Enter choce of operation: ");
    scanf("%d", &ch);
    return ch;
}

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d  ", head->data);
        head = head->next;
    }
}

struct Node * AddNode(struct Node *head, int data)
{
    struct Node *newNode;
    struct Node *p;
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    
    if (newNode == NULL) 
    {    
        return head; 
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

}


int main()
{
    int ch = 0;
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));

    while(1)
    {
        printf("\n ~~~MENU~~~");
        printf("\nOperation 1: Add Node");
        printf("\n");
        printf("Enter choice of operation: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                int data;
                printf("\nData to be added: ");
                scanf("%d", &data);
                head = AddNode(head, data);
                printf("\n");
                display(head);
                printf("\n");
                break;
            }
            case 22:
            {
                printf("Exiting Operations");
                exit(0);
            }

            default:
            {
                printf("Please choose valid operation");
                break;
            }
        }
    }
    

    return 0;
}