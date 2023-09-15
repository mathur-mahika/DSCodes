#include <stdio.h>
#define p printf
#define s scanf
void QS(int [], int, int);
int partition(int [], int, int);

int main()
{
	return 0;
}

int partition(int a[], int l, int h)
{
	
}

void QS(int a[], int l, int h)
{
	if (low < high) 
	{
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
    }
}