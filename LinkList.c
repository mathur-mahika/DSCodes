#include <stdio.h>
#define p printf
#define s scanf
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node *ptr)
{
	while(ptr!=NULL)
	{
		p("%d\n", ptr->data);
		ptr = ptr->next;
	}	
}

struct node * concat(struct node *ptr1, struct node *ptr2)
{
	struct node *p = ptr1;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = ptr2;
	return ptr1;
}

int main()
{
	struct node *head1, *first1, *second1,*head2, *first2, *second2;
	head1 = malloc(sizeof(struct node));
	first1 = malloc(sizeof(struct node));
	second1 = malloc(sizeof(struct node));
	head2 = malloc(sizeof(struct node));
	first2 = malloc(sizeof(struct node));
	second2 = malloc(sizeof(struct node));

	head1->data = 1;
	head1->next = first1;
	first1->data = 2;
	first1->next = second1;
	second1->data = 3;
	second1->next = NULL;

	head2->data = 4;
	head2->next = first2;
	first2->data = 5;
	first2->next = second2;
	second2->data = 6;
	second2->next = NULL;

	/*
	p("%d", head->data);
	p("\n%d", ptr->data);
	p("\n%d", ptr1->data);

	struct node *temp = head;
	head = head->next;
	free(temp);
	p("\n%d", head->data);
	*/

	p("Before:\n\n");
	display(head1);
	p("\n");
	display(head2);

	p("After:\n\n");
	head1 = concat(head1, head2);
	display(head1);

 	return 0;
}
