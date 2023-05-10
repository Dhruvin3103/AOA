#include<stdio.h>
#include<string.h>
int pie[100];
void prefix_fun(char p[])
{
    int k=0;
    pie[0]=0;
    // printf("hi");
    for(int i=1; i<strlen(p);i++)
    {
        // printf("\nk %d",k);
        while(k>0 && p[k]!=p[i])
        {
            k=pie[k];
        }
        // printf("|%c %c- %d %d|",p[k],p[i],k,i);
        if(p[k]==p[i])
            {// {printf("|%c %c|",p[k],p[i]);
            k+=1;}
        pie[i]=k;
    }
}

// int *retarr(int *p)
// {
//     printf("%c",p[0]);
//     p[0]=p[0]+"h";
//     printf("%c",p[0]);
//     return p;
// }

void main()
{
    int tlen,plen,q=0;
    char text[200]="ababcabcabababd",pat[100]="abc";
    tlen = strlen(text);
    plen = strlen(pat);
    prefix_fun(pat);
    // printf("\nLength : %d %d\n",tlen,plen);
    for(int i=0;i<tlen;i++)
    {
        // printf("|%d|",q);
        while(q>0 && pat[q]!=text[i])
        {
            
            q=pie[q-1];
            // printf("\npie %c %c %d\n",pat[q],text[i],q);
        }
        if(pat[q]==text[i])
        {
            // printf("\n+ %c %c %d\n",pat[q],text[i],q);
            q+=1;
        }
        if(q==plen)
        {
            printf("pattern occurs at %d",i-plen+1);
            printf("\n");
            for(int j=(i-plen+1);j<i+1;j++)
            {printf("%c",text[j]);}
            q=pie[q-1];
        }
    }

}
