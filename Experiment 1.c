#include<stdio.h>
#include <time.h>
#include <stdlib.h> 
void insertion(int a[], int n)
{
    int j;
    for(int i =1;i<n;i++)
    {
        int temp = a[i];
        j=i-1;
        while(a[j]> temp && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]= temp;
    }
}


int main()
{
    clock_t t;
    int n,a[150000],b;
    printf("Enter the size : ");
    scanf("%d",&n);
    //Average case
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    t = clock();
    insertion(a, n);
    t = clock()-t;
    double t1 = ((double)t);
    printf("Exution time Average case: %f",t1);
    //Best case
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    t = clock();
    insertion(a, n);
    t = clock()-t;
    double t2 = ((double)t);
    printf("\nExution time Best case : %f",t2);
    //Worst case
    //Best case
    int x =n;
    for(int i=0;i<n;i++)
    {
        a[i]=x;
        x--;
    }
    t = clock();
    insertion(a, n);
    t = clock()-t;
    double t3 = ((double)t);
    printf("\nExution time Worst case : %f",t3);
    
    
}
