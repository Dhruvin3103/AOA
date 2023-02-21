#include<stdio.h>
#include <time.h>
#include <stdlib.h> 
int small(int a[],int p, int n)
{
    int small = a[p],pos=p;
    for(int i = p+1 ;i<n;i++)
    {
        if(a[i]<small)
        {
            small=a[i];
            pos=i;
        }
    }
        return pos;
}

void select1(int a[],int n)
{
    int pos,temp;
    
    for(int i=0;i<n;i++)
    {
        pos = small(a,i,n);
        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
    }
}

int main()
{
    clock_t t;
    int n,a[150000],b;
    printf("Enter size : ");
    scanf("%d",&n);
    //Average case
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    t = clock();
    select1(a, n);
    t = clock()-t;
    double t1 = ((double)t);
    printf("Exution time Average case: %f",t1);
    //Best case
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    t = clock();
    select1(a, n);
    t = clock()-t;
    double t2 = ((double)t);
    printf("\nExution time Best case : %f",t2);
    //Worst case
    //Best case
    for(int i=0;i<n;i++)
    {
        a[i]=n;
        n--;
    }
    t = clock();
    select1(a, n);
    t = clock()-t;
    double t3 = ((double)t);
    printf("\nExution time Worst case : %f",t3);
    
    
}
