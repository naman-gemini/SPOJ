#include<stdio.h>
#include<math.h>

int a0[]= {1};
int a1[400000]= {0};
int a2[400000]= {0};
int a3[400000]= {0};
int a4[400000]= {0};
int a5[400000]= {0};
int a6[3000]= {0};
int a7[500]= {0};
int a8[500]= {0};
int a9[500]= {0};
int a10[500]= {0};

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

int primeFactor(int n)
{
    int i,j,k,x=0;
    if(n==1) return;

    if(n%2==0)
    {
        x++;
        while(n%2==0)
            n=n/2;
    }

    for(i=3; i<=n; i+=2)
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
                x++;
            }

            if(x>10) break;
        }
    }
    return x;
}

void precalculate()
{
    int i,p;
    int b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0,b10=0;
    for(i=1; i<=1000000; i++)
    {
        p=primeFactor(i);
        switch(p)
        {
        case 1:
            a1[b1]=i;
            b1++;
            break;

        case 2:
            a2[b2]=i;
            b2++;
            break;

        case 3:
            a3[b3]=i;
            b3++;
            break;

        case 4:
            a4[b4]=i;
            b4++;
            break;

        case 5:
            a5[b5]=i;
            b5++;
            break;

        case 6:
            a6[b6]=i;
            b6++;
            break;

        case 7:
            a7[b7]=i;
            b7++;
            break;

        case 8:
            a8[b8]=i;
            b8++;
            break;

        case 9:
            a9[b9]=i;
            b9++;
            break;

        case 10:
            a10[b10]=i;
            b10++;
            break;
        }
    }
}

int binary_search(int key, int a[])
{
    int min,max,mid;
    min=0;
    max=400000;
    mid=(min+max)/2;

    while(1)

    {
        mid=(min+max)/2;
        if(a[mid]==key) return mid;

        if(key<a[mid]) max=mid-1;
        else min=mid+1;

        if(min>max) return -1;
    }
}

int main()
{
    int n,a,b;
    int t;
    scanf("%d",&t);
    precalculate();
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&n);
        int counter=0;
        switch (n)
        {
            case 1:
            while(a<=b)
            {
                if(a==a1[binary_search(a,a1)]) counter++;
            }
            printf("%d\n",counter);
            break;
        }
    }
}

