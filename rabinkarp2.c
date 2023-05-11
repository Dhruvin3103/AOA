#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
    char txt[] = "xyzahxyfxyzd";
    char pat[] = "xyz";
    int pathash=0,i,j,k,txthash,flag=0;
    for(i=0;i<strlen(pat);i++)
    pathash+=pat[i]*pow(10,strlen(pat)-i-1);
    for(i=0;i<strlen(txt);i++)
    {
        txthash=0;
        for(j=i,k=0;j<strlen(pat)+i;j++,k++)
        txthash+=txt[j]*pow(10,strlen(pat)-k-1);
        if(txthash==pathash)
        {
            printf("String Matched at index %d\n",i);
            flag=1;
        }
    }
    if(flag==0)
    printf("String not matched");
}
