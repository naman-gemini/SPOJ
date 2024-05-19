#include<stdio.h>
#define MAX 1000001
int arr[MAX];
int check[MAX];

void precal()
{
    int i,j,k,x;
    for(i=2;i*i*i<MAX;i++)
    {
        k=i*i*i;
        for(j=k;j<MAX;j+=k)
        arr[j]=1;
    }

    check[0]=1;

    for(i=2,x=1;i<MAX;i++)
    {
        if(arr[i]==0)
        {
            check[x]=i;
            x++;
        }

    }
}

int search(int n)
{
    int mid,min=0,max=n;
    while(1)
    {
        mid=(min+max)/2;
        if(check[mid]==n) return mid+1;


        if(n<check[mid]) max=mid-1;
        else min=mid+1;
    }

}

int main()
{
    precal();
    int t,k,x=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        if(k==1)
        {
            printf("Case %d: 1\n",x++);
            continue;
        }
        if(arr[k]==1) printf("Case %d: Not Cube Free\n",x);

        else printf("Case %d: %d\n",x,search(k));
        x++;

    }
    return 0;
}
