#include<stdio.h>
#include<math.h>


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

void primeFactor(int a[],int n)
{
    int i,j,k,x=0;

    if(n==1) return;

    if(n%2==0)
    {
        a[0]=2;
        x++;
        while(n%2 == 0)
        {
            n=n/2;
        }
    }

    for(i=3;i<=n;i+=2)
    {
        k=0;
        if(n%i==0)
        {
            if(isPrime(i))
            {
                k++;
                while(n%i==0)
                n=n/i;
            }

            if(k==1)
            {
                a[x]=i;
                x++;
                if(x==10) break;
            }
        }
    }
}

int main()
{
    int t,a,b,n,i,j,k,counter,counter1;
    scanf("%d",&t);
    while(t--)
    {

        counter=0;
        scanf("%d %d %d",&a,&b,&n);
        for(i=a;i<=b;i++)
        {
            counter1=0;
            int array[10]={0};
            primeFactor(array,i);

            for(j=0;j<10;j++)
            if(array[j]!=0) counter1++;
            if(counter1==n) counter++;

        }
        printf("%d\n",counter);
    }

    return 0;
}
