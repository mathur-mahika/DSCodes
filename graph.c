//adjacency matrix

#include <stdio.h>
#define V 4

void init(int arr[][V])
{
    int i, j;
    for(i = 0; i < V; i++)
    {
        for(j = 0; j <V; j++)
        {
            arr[i][j]=0;
        }
    }
}

void addEdge(int arr[][V], int i, int j)
{
    arr[i][j]=1;
    arr[j][i]=1;
}

void printAdjMatrix(int arr[][V])
{
    int i, j;
    for(i = 0; i < V; i++)
    {
        for(j = 0; j <V; j++)
        {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int adjMatrix[V][V];

    init(adjMatrix);
    printAdjMatrix(adjMatrix);
    printf("\n");
    addEdge(adjMatrix, 0 ,1);
    addEdge(adjMatrix, 0 ,2);
    addEdge(adjMatrix, 1 ,2);
    addEdge(adjMatrix, 2 ,1);
    addEdge(adjMatrix, 2 ,0);
    printAdjMatrix(adjMatrix);

    return 0;
}