    #include <stdio.h>
    #include <stdlib.h>
    #define p printf
    #define s scanf

    struct Node
    {
    int data;
    struct Node* next;
    struct Node* prev;
    };

    void displayList(struct Node* head)
    {
    while(head != NULL)
    {
    p("%d\n", head->data);
    head = head->next;
    }
    }

    struct Node* createNode(int data)
    {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
    }

    struct Node* insertNode_first(int data, struct Node* head)
    {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL)
    {
    head->prev = newNode;
    }
    return newNode;
    }

    struct Node* insertNode_last(int data, struct Node* head)
    {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* ptr = head;
    while(ptr->next != NULL)
    {
    ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    newNode->prev = ptr;

    return head;
    }

    struct Node* insertNode_index(int data, struct Node* head, int index)
    {
    int c=0;
    struct Node* temp = head;
    while(temp != NULL)
    {
    temp = temp->next;
    c++;
    }
    if(index > c)
    {
    p("invalid index");
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if(index == 0)
    {
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL)
    {
    head->prev = newNode;
    }
    return newNode;
    }
    else if(index>0)
    {
    int i;
    struct Node* ptr = head;
    while(i != index-1)
    {
    ptr = ptr->next;
    i++;
    }
    newNode->next = ptr->next;
    newNode->prev = ptr;
    if(ptr->next != NULL)
    {
    ptr->next->prev = newNode;
    }
    ptr->next = newNode;
    return head;
    }
    return head;
    }

    struct Node* deleteNode(struct Node* head, int index)
    {
    int c=0;
    struct Node* temp = head;
    while(temp != NULL)
    {
    temp = temp->next;
    c++;
    }
    if(index > c)
    {
    p("invalid index");
    }
    if(index == 0)
    {
    struct Node* ptr = head;
    head = head->next;
    if(head != NULL)
    {
    head->prev = NULL;
    }
    free(ptr);
    return head;
    }
    else if(index > 0)
    {
    int i=0;
    struct Node* p = head;
    struct Node* q = head->next;
    while(i != index-1)
    {
    p = p->next;
    q = q->next;
    i++;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return head;
    }
    return head;
    }

    struct Node* reverseList(struct Node** head)
    {
    struct Node* temp = NULL;
    struct Node* ptr = *head;

    while(ptr != NULL)
    {
    temp = ptr->next;
    ptr->next = ptr->prev;
    ptr->prev = temp;
    ptr = ptr->prev;
    }
    *head = temp->prev;
    return *head;
    }

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    int choice;

    while(1)
    {
    p("Enter choice of operation");
    p("\n1. Create 1st node: ");
    p("\n2. Insertion at specefic index: ");
    p("\n3. Insertion at start: ");
    p("\n4. Insertion at end: ");
    p("\n5. Deletion: ");
    p("\n0. Exit");
    p("\nEnter choice: ");
    s("%d", &choice);
    switch(choice)
    {
    case 1:{
    int data;
    p("Enter data: ");
    s("%d", &data);
    head = createNode(data);

    displayList(head);

    break;
    }
    case 2:{
    int data1, index1;
    p("Enter data: ");
    s("%d", &data1);
    p("Enter index: ");
    s("%d", &index1);

    head = insertNode_index(data1, head, index1);

    displayList(head);

    break;
    }
    case 3:{
    int data;
    p("Enter data: ");
    s("%d", &data);
    head = insertNode_first(data, head);

    displayList(head);

    break;
    }
    case 4:{
    int data;
    p("Enter data: ");
    s("%d", &data);
    head = insertNode_last(data, head);

    displayList(head);

    break;
    }
    case 5:{
    int index2;
    p("Enter index: ");
    s("%d", &index2);

    head = deleteNode(head, index2);

    displayList(head);

    break;
    }
    case 0:{
    exit(0);
    break;
    }
    default:{
    p("Enetr valid operation!");
    break;
    }
    }
    }


    /*
    struct Node* one = (struct Node*)malloc(sizeof(struct Node));
    struct Node* two = (struct Node*)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = one;
    head->prev = NULL;

    one->data = 9;
    one->next = two;
    one->prev = head;

    two->data = 21;
    two->next = NULL;
    two->prev = one;
    */

    return 0;
}