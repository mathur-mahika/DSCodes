#include <stdio.h>
#define p printf
#define s scanf

int BS(int a[], int l, int h, int k)
{
	int mid = (l+h)/2;
	if(l<=h)
	{
		if(a[mid] == k)
		{
			return a[mid];
		}
		if(a[mid] > k)
		{
			return BS(a, l, mid-1, k);
		}
		return BS(a, mid+1, h, k);
	}
	return -1;
}
int main()
{
	int arr[5] = {3, 5, 11, 12, 17}, low = 1, high = 5, key = 17, ans;
	
	ans = BS(arr, low, high, key);
	p("key found %d", ans);
	
	return 0;
}
