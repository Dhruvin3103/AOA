#include <stdio.h>
#include <stdlib.h>
#define n 10
int i, a[n];
int max, min;
void maxmin(int a[], int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            maxmin(a, i, mid);
            max1 = max;
            min1 = min;
            maxmin(a, mid + 1, j);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    printf("Element in array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    max = a[0];
    min = a[0];
    maxmin(a, 0, n);
    printf("\nMinimum element in an array : %d\n", min);
    printf("Maximum element in an array : %d\n", max);
    return 0;
}