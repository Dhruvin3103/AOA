
#include<stdio.h>
#include<stdlib.h>

int parent[10];
void main()
{
    int i,j,n,ne=1,a,b,u,v;
    int min;
    int mincost=0;
    int parent[10],cost[10][10];
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }
        }
    }
    
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        
        u=find(u);
        v=find(v);
        
        if(uni(u,v))
        {
            printf("Edge %d:(%d %d) cost:%d\n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Minimum cost:%d\n",mincost);
}

int find(int i)
{
    while(parent[i])
    {
        i=parent[i];
    }
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
