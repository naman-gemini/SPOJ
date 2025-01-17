#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
ll MOD=ll( 1000000007);
ll Fibo(int n)
{
    ll fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    for(int k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j])%MOD;
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                for(int k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j])%MOD;
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                fib[i][j]=tmp[i][j];
        n/=2;

    }
    return (ret[0][1])%MOD;
}

int main()
{
    int t,m,n;
    for(scanf("%d",&t); t>0; t--)
    {
        scanf("%d%d",&n,&m);
        cout<<(Fibo(m+2)-Fibo(n+1)+MOD)%MOD<<endl;;
    }
    return 0;
}
