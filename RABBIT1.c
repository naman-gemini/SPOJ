#include<stdio.h>
#include<math.h>
typedef unsigned long long ll;


ll f(int n,int m)
{
    ll  fib[2][2]= {{1,1},{1,0}},base[2][2]= {{1,1},{1,0}},tmp[2][2]= {{0,0},{0,0}};;
    ll MOD = pow(2,m);
    int i,j,k;

    while(n)
    {
        for( i=0; i<2; i++)
                for( j=0; j<2; j++)
                tmp[i][j]=0;

        if(n&1)
        {
            //memset(tmp,0,sizeof tmp);
            for( i=0; i<2; i++)
                for( j=0; j<2; j++)
                    for( k=0; k<2; k++)
                        tmp[i][j]+=(fib[i][k]*base[k][j]);

            for( i=0; i<2; i++)
                for( j=0; j<2; j++)
                    {
                        fib[i][j]=tmp[i][j];
                        //printf("tmp[%d][%d]=%lld\t",i,j,tmp[i][j]);
                    }
        }


        else
        {
            //memset(tmp,0,sizeof tmp);
            for( i=0; i<2; i++)
                for( j=0; j<2; j++)
                    for( k=0; k<2; k++)
                        tmp[i][j]+=(fib[i][k]*fib[k][j]);

           for( i=0; i<2; i++)
                for( j=0; j<2; j++)
                    {
                        fib[i][j]=tmp[i][j];
                        //printf("tmp[%d][%d]=%lld\t",i,j,tmp[i][j]);
                    }
        }

        n/=2;
       // printf("\n");

    }
    return (fib[0][1]);
}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        printf("%lld\n",f(n,m));
    }
    return 0;
}
