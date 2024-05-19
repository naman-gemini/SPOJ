#include<stdio.h>
#define N 1000002
int arr[N];

int main()
{
    int k,l,n,i,c;
    scanf("%d %d %d",&k,&l,&n);
    for(i=1;i<=N;i++)
    {
        if(arr[i-1]==0)
        arr[i]=1;

        else if(i-k>=0 && arr[i-k]==0)
        arr[i]=1;

        else if(i-l>=0 && arr[i-l]==0)
        arr[i]=1;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&c);
        if(arr[c]) printf("A");
        else printf("B");
    }
    printf("\n");
    return 0;
}
