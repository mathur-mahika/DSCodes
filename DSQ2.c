#include <stdio.h>
#include <stdlib.h>
#define p printf
#define s scanf

struct Node{
	int data;
	struct Node *next;
};

void display(struct Node *ptr)
{
	while(ptr!=NULL)
	{
		p("%d\n", ptr->data);
		ptr = ptr->next;
	}	
}

struct Node* insert_index(struct Node* head, int data, int index)
{
    
}