#include<stdio.h>
#include<time.h>
#include <stdlib.h>
int part(int a[],int l,int h)
{
    int p = a[h];//pivot
    int i=l;
    // printf("%d",i);
        for(int j=l;j<h;j++)
        {
            if(a[j]<=p)
            {int temp=a[i];a[i]=a[j];a[j]=temp;i++;}//swapping i and j 
        }
        int t2=a[i];a[i]=a[h];a[h]=t2; //swapping I and h
        return i;
}

//8 1 3 2 6 5 7 4 12 9 11 10 14 13 15
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int j= part(a,l,h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
    }
}

void main()
{
    int n, a[1500000];
    clock_t t;
    printf("enter the size : ");
    scanf("%d",&n);
    int x=n;
    
    for(int i=0;i<n;i++)
    {
      a[i]=i;
    }
    
    t= clock();
    quicksort(a,0,n);
    t = clock()-t;
    double t1 = (double)t;
    printf("Excution time for ascen elements is : %f \n",t1);
    
    //sorted descending
    for(int i=0;i<n;i++)
    {
      a[i]=x;
      x--;
    }
    
    t= clock();
    quicksort(a,0,n);
    t = clock()-t;
    double t3 = (double)t;
    printf("Excution time for desc elements is : %f \n",t3);
    
    // best case 
    for(int i=0;i<n;i++)
    {
      a[i]=rand();
    }
    t= clock();
    quicksort(a,0,n-1);
    t = clock()-t;
    double t2 = (double)t;
    printf("Excution time for rand is : %f ",t2);
    
    
    
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d\t",a[i]);
    // }
}