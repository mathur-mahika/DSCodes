//traversing a link list

#include <stdio.h>
#define p printf
#define s scanf
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*head;

void createlist(int n);
void traverselist();

int main()

{
	int n;
	p("Enter n: ");
	s("%d", &n);
	
	createlist(n);
	
	traverselist();
 	return 0;
}

void createlist(int n)
{
	int data;
	head = malloc(sizeof(struct node));
	head->data = n;
	
	if(head == NULL)
	{
		p("Um no this ain't working gurl");
		exit(0);
	}
}

void traverselist()
{
	p("this is me printing that, this is my node that i made and here is value %d", head->data);
}