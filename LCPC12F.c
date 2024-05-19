#include<stdio.h>
#include<algorithm>
#define DEBUG(x) printf(#x"=%d\n",x)
typedef long long ll;
int a[100005];
int b[2][100005];

int bs(int **arr,int size,int key)
{
    int low,high,mid;
    low=0;
    high=size-1;
    mid=0;
    while(arr[0][mid]!=key && low<high)
    {
        mid=(low+high)/2;
        if(arr[0][mid]<key) low=mid+1;
        else high=mid+1;
    }
    if(arr[0][mid]==key) return 1;
    else return 0;
}

int main()
{
    int t,x,n,curr,count,tcount;
    ll ans,cs,i,j;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        //memset(a,0,sizeof(a));
        //memset(b,0,sizeof(b));
        tcount=0;
        ans=0;
        scanf("%d %d",&x,&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=0,j=0;i<n;j++)
        {
            count=0;
            curr=a[i];

            while(a[i]==curr)
            {
                i++;
                count++;
            }
            b[0][j]=curr;
            b[1][j]=count;
            tcount++;

        }

        for(i=0;i<tcount;i++)
        {
            if(bs(b,tcount,x-b[0][i]))
            printf("TRUE\n");
            else printf("FALSE\n");
        }
        printf("%d. %d\n",cs,ans);
    }
    return 0;
}
