#include <stdio.h>
#define MAX 9
#define INFINITY 9999

int g[MAX][MAX] = {{0, 11, 0, 0, 0, 0, 0, 8, 0},
                   {11, 0, 8, 0, 0, 0, 0, 11, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
                   {0, 0, 4, 14, 10, 0, 2, 0, 0},
                   {0, 0, 0, 0, 0, 2, 0, 1, 6},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
                   {0, 0, 2, 0, 0, 0, 6, 7, 0}};

int min1(int d[], int v[], int n)
{
    int f = 0, b[MAX];
    int m, l = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (v[i] == 0)
        {
            m = d[i];
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (d[i] <= m && v[i] == 0)
        {
            m = d[i];
            {
                l = i;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            f = f + 1;
        }
    }
    if (f == n)
    {
        return -1;
    }
    return l;
}

int mindist(int d[], int par[], int u, int v)
{
    if (g[u][v] != 0 && d[v] > d[u] + g[u][v])
    {
        d[v] = d[u] + g[u][v];
        par[v] = u;
    }
    return u;
}

int main()
{
    int d[MAX], par[MAX], v[MAX] = {0};
    int x = 0, s = 0; // source
    d[0] = 0;
    par[0] = -1;
    for (int i = 1; i < MAX; i++)
    {
        d[i] = INFINITY;
    }

    do
    {
        if (v[x] == 0)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (g[x][j] != 0)
                {
                    mindist(d, par, x, j);
                }
            }
        }
        v[x] = 1;
    } while ((x = min1(d, v, MAX)) != -1);

    printf("\nvertex\tdistance from source\tparent");
    for (int i = 0; i < MAX; i++)
    {
        printf("\n%d\t\t%d\t\t\t\t\t\t%d", i, d[i], par[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        int j;
        if (i != s)
        {
            j = i;
            printf("\nFrom %d  : %d<-", i, i);
            while (par[j] != s)
            {
                printf("%d<-", par[j]);
                j = par[j];
            }
            printf("%d", s);
        }
    }

    return 0;
}
