#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int isPrime (int n)
{
    int i;
    if(n==2 || n==3) return 1;
    if(n%2==0 || n%3==0) return 0;              //returns 1 for prime

    if(n%6==1 || n%6==5)
    {
        int p=(int)(sqrt(n));
        for(i=3; i<=p; i+=2)
        {
            if(n%i==0)
                return 0;
        }
    }
    return 1;
}

long long int power[10005];
void factorize(int i)
{
    while(i%2==0 && i>0)
    {
        i/=2;
        power[2]++;
    }

    for(int j=3 ; j<= i ; j+=2)
    {
        if(isPrime(j)&& i%j==0 && i>0)
        {
            i/=j;
            power[j]++;
        }
    }
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        memset(power,0,10005);
        for(int i=2; i<=t; i++)
        {
            factorize(i);
        }
        //printf("%d\n",power[2]);

        for(int i=2;i<=t;i++)
        {
            if(power[i]!=0)
            {
                printf("%d^%lld",i,power[i]);
                printf(" * ");
            }
        }
        //printf("\n");
        printf("\b\b \n");
    }
    return 0;

}
