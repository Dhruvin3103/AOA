#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
int prim[100][100];
#define V 5

int mindist(int dist[], bool visited[])
{
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && dist[v] < min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void initialize(int dist[V], bool visited[V], int parent[], int source)
{
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    dist[source] = 0;
    parent[source] = -1;
}

void primMST(int graph[V][V],int src)
{
    int parent[V];
    int dist[V];
    bool visited[V];
    initialize(dist, visited, parent, src);

    for (int i = 0; i < V - 1; i++)
    {
        int u = mindist(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && visited[v] == false && graph[u][v] < dist[v])
            {
                prim[u][v] = 1;
                dist[v] = graph[u][v];
            }
    }
    printPrim();
}

void printPrim()
{
    for (int o = 0; o < V; o++)
    {
        for (int y = 0; y < V; y++)
        {
            printf("%d ", prim[o][y]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    primMST(graph,0);

    return 0;
}
