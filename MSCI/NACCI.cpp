#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,l,temp=0,x;
        scanf("%d %d %d",&n,&k,&l);
        k=pow(10,k);
        int *a;
        a=(int*)malloc(sizeof(int)*n);
        for(int i=0; i<n; i++)
        {
            a[i]=i;
        }

        l=l-n+1;
        while(l--)
        {
            temp=a[n-1];
            x=0;

            //finding new value
            for(int i=0; i<n-1; i++)
            {
                x+=(a[i]%k);
                a[i]=a[i+1];
            }
            x+=(temp%k);

            //shifting all values
//            for(int i=0; i<n-1; i++)
//            {
//                a[i]=a[i+1];
//            }
            a[n-1]=x;
        }
        printf("%d\n",a[n-1]%k);
    }
    return 0;
}
