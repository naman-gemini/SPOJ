#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a,dd,n;
    long long int min,max,res;
    scanf("%d %d",&n,&dd);
    for(int i=0; i<n; i++)
    {
        int temp=0;
        for(int j=0; j<dd; j++)
        {
            scanf("%d",&a);
            temp+=a;
        }
        if(i==0)
        {
            min=temp;
            max=temp;
        }
        else
        {
            if(min>temp) min=temp;
            if(max<temp) max=temp;
        }
    }
    res=max-min;
    if(res< 0) res=res*(-1);
    printf("%lld\n",res);
    return 0;
}
