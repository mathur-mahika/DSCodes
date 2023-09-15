#include <stdio.h>
#define p printf
#define s scanf

int BSI(int [], int, int, int);

int BSI(int a[], int k, int l, int h)
{
	int i, mid = (l+h)/2;
	
	if(a[mid] == k)
	{
		return mid+1;
	}
	else if(a[mid] < k)
	{
		for(i = mid+1; i < h; i++)
		{
			if(a[i] == k)
			{
				return i+1;
			}
		}
	}
	else if(a[mid > k])
	{
		for(i = 0; i < mid-1; i++)
		{
			if(a[i] == k)
			{
				return i+1;
			}
		}
	}
	else
	{
		return -1;
	}
}

int main()
{
	int arr[5] = {3, 5, 11, 12, 17}, low = 0, high = 4, key, ans;
	
	p("Enter key: ");
	s("%d", &key);
	
	ans = BSI(arr, key, low, high);
	
	if(ans == -1)
	{
		p("Key doesn't exist");
	}
	else
	{
		p("key found at %d", ans);
	}
	return 0;
}
