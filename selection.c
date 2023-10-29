#include <stdio.h>

void selectionSort(int arr[], int n) 
{
    int i, j, minI, temp;
    
    for (i = 0; i < n - 1; i++) 
    {
        minI = i;

        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minI]) 
            {
                minI = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minI];
        arr[minI] = temp;
    }
}

int main() 
{
    int arr[] = {64, 25, 12, 22, 11};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    selectionSort(arr, n);
    
    printf("\nSorted array: ");

    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
