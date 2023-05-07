#include <stdio.h>

int x[100];

void printa(int w[], int k)
{
    printf("\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t", x[i]);
    }
    printf("{ ");
    for (int i = 0; i < k; i++)
    {
        if (x[i] == 1)
        {
            printf("%d ", w[i]);
        }
    }
    printf("}");
}

void sos(int s, int k, int r, int w[], int m, int n)
{
    // printf("\ns : %d, k: %d, r: %d, x%d : %d\n",s,k,r,k,x[k-1]);
    x[k] = 1;
    if (s + w[k] == m)
    {
        printa(w, n);
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        sos(s + w[k], k + 1, r - w[k], w, m, n);
    }
    if (s + r - w[k] >= m && s + w[k + 1] <= m)
    {
        for (int i = k; i < n; i++)
        {
            x[i] = 0;
        }
        x[k] = 0;
        sos(s, k + 1, r - w[k], w, m, n);
    }
}

void main()
{
    int w[] = {2, 3, 5, 6, 8, 10}, m = 10;
    int n = sizeof(w) / sizeof(w[0]);
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        r = w[i] + r;
    }
    // printf("%d", r);
    printf("possible subsets  : \n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d\t", i + 1);
    }
    sos(0, 0, r, w, m, n);
}