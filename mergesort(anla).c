#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#define MAX 150000
void merge(int a[],int beg,int mid,int end)
{
    int i,j,k,temp[MAX],index;
    i=beg;
    j=mid+1;
    index=beg;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            temp[index]=a[i];
            i++;
        }
        else
        {
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
    a[k]=temp[k];
}
void mergesort(int a[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
void main()
{
    int i,a[MAX],n;
    clock_t t,t1,t2;
    printf("Enter number of terms ");
    scanf("%d",&n);
    int x= n;
    //best case
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    t = clock();
    mergesort(a,0,n-1);
    t = clock()-t;
    printf("Excution time : %f \n",(double)(t));
    
    //worst case desc sort 
    for(int i=0;i<n;i++)
    {
        a[i]=x;
        x--;
    }
    t1 = clock();
    mergesort(a,0,n-1);
    t1 = clock()-t1;
    printf("Excution time : %f\n",(double)(t1));
    
    
    //worst case desc sort 
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    t2 = clock();
    mergesort(a,0,n-1);
    t2 = clock()-t2;
    printf("Excution time : %f",(double)(t2));
}