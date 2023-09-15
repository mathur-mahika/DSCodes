#include <stdio.h>

int main ()
{
    int flag, rounds = 0, temp = 0;

    int arr[] = {4, 2, 8, 10, 3};
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        rounds++;
        flag = 0;

        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;   
            }
        }
        
        if (flag == 0)
        {
            break;
        }

       
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The number of rounds it took to sort: %d", rounds);
    
}