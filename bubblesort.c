#include <stdio.h>
#define p printf
#define s scanf

void bubble_sort(int [], int);

void bubble_sort(int a[], int l)
{
	int i, j, temp;

	for(i = 0; i < (l - 1); i++)
	{
		for(j = 0; j < (l - 1 - i); j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	p("\nThe sorted array is: ");

	for(i = 0; i < l; i++)
	{
		p("%d ", a[i]);
	}
}

int main()
{
	int size, i;
	int arr[] = {3, 6, 2, 9, 1};
	size = sizeof(arr)/sizeof(arr[0]);
	
	bubble_sort(arr, size);
	
	return 0;
}

