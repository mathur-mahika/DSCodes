#include <stdio.h>
#define p printf
#define s scanf

void LS(int [], int);

void LS(int a[], int k)
{
	int i;
	
	for(i = 0; i < 5; i++)
	{
		if(a[i] == k)
		{
			printf("Positin of key is %d", i+1);
			
		}
		
	}
}

int main()
{
	int arr[5] = {3, 5, 11, 17, 12}; 
	int key = 11;
	
	LS(arr, key);
	
	return 0;
}


