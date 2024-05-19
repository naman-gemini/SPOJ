#include<cstdio>
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
typedef unsigned long long ll;

ll Fibo(int n,int m)
	{
	    ll MOD=pow(2,m);
		ll  fib[2][2]={{1,1},{1,0}},ret[2][2]={{1,0},{0,1}},tmp[2][2]={{0,0},{0,0}};
		while(n)
		{
			if(n&1)
			{
				memset(tmp,0,sizeof tmp);
				for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
						tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j])%MOD;
				for(int i=0;i<2;i++) for(int j=0;j<2;j++) ret[i][j]=tmp[i][j];
			}
			memset(tmp,0,sizeof tmp);
			for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
                                   tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j])%MOD;
                        for(int i=0;i<2;i++) for(int j=0;j<2;j++) fib[i][j]=tmp[i][j];
			n/=2;

		}
		return (ret[0][0])%MOD;
	}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        printf("%lld\n",Fibo(n,m));
    }
    return 0;
}
