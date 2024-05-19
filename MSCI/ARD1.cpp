#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
ll MOD=ll( 123456789 );
ll Fibo(ll n)
{
    ll fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j])%MOD;
            for(int i=0; i<2; i++) for(int j=0; j<2; j++) ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j])%MOD;
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (ret[0][1])%MOD;
}

int main()
{
    int t;
    ll n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1) {printf("3\n"); continue;}
        if(n==2) {printf("8\n"); continue;}
        //n+=2;
        printf("%lld\n",2*Fibo(n-1)+3*Fibo(n+1));
    }
    return 0;
}
