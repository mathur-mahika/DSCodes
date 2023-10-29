#include <stdio.h>

void insertEdge(int adjMatrix[][100], int src, int dest) 
{
    adjMatrix[src][dest] = 1;
}

void displayMatrix(int adjMatrix[][100], int ver) 
{
    int i, j;
    for (i = 0; i < ver; i++) {
        for (j = 0; j < ver; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int ver, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &ver);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int adjMatrix[100][100] = {0}; 

    for (int i = 0; i < edges; i++) 
    {
        int src, dest;

        printf("Enter edge %d (source): ", i + 1);
        scanf("%d ", &src);

        printf("Enter edge %d (destination): ", i + 1);
        scanf("%d ", &dest);

        if (src < ver && dest < ver) 
        {
            insertEdge(adjMatrix, src, dest);
        } 
        else 
        {
            printf("Invalid input. Vertex index out of range.\n");
            i--;
        }
    }

    printf("Adjacency Matrix:\n");
    displayMatrix(adjMatrix, ver);

    return 0;
}
