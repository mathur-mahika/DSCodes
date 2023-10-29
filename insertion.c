#include <stdio.h> 

void insertion_sort(int *a, int n) 
{
    int i, j, key = 0;

    for (i = 0; i < n; i++)
    { 
        key = a[i];
        j = i-1;
        
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;    
    }

    for (int i = 0; i < n; i++)
    {
       printf(" %d ", a[i]);
    }  
}

int main() 
{    
    int arr[] = {5, 2, 1, 3, 4, 6};
    int n = 6;

    printf("The array before sorting: \n");
    printArray(arr, n);

    insertion_sort(arr, n);
    printf("The sorted array: \n");
    printArray(arr, n);

    return 0;
}
