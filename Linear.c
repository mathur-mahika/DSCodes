#include <stdio.h>

int linearSearch(int a[], int l, int k) 
{
    int num = 0;
    for (int i = 0; i < l; i++) 
    {    
        if (a[i] == k) 
        {
            num = a[i];
        }
    }
    return num;
}

int main() 
{    
    int arr[] = {2, 4, 0, 1, 9};
    int key;

    printf("Enter number to search: ");
    scanf("%d", &key);

    int len = sizeof(arr) / sizeof(arr[0]);
    
    int result = linearSearch(arr, len, key);

    printf("The linearly searched number is: %d ", result);
    
    return 0;
}
