#include<stdio.h>
long long int arr[1000000];
int a[10],b[10];

int check(long long int n)
{
    while(n !=0 )
    {
        a[n%10]++;
        n/=10;
    }
    n*=2;

    while(n !=0 )
    {
        b[n%10]++;
        n/=10;
    }
    int i;
    for(i=0;i<10;i++)
    if(a[i]!=b[i]) return 0;
    return 1;
}

long long int precal()
{
    long long int i,x;
    for(i=1,x=1;i<1000000000;i++)
    {
        if(check(i))
        {
            arr[x]=i;
            x++;
        }
    }
}

int main()
{
    long long int a,b;
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        //precal();
        //for(i=1;i<20;i++)
        //printf("%d\t",arr[i]);
        //scanf("%lld %lld",&a,&b);

        printf("%d\n",check(499875921));

    }
    return 0;


}
