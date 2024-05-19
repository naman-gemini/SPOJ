#include <stdio.h>
#include <stdlib.h>
#include<cstring>

typedef	long long bigint;
bigint array[11][65];

#include<iostream>
using namespace std;
bigint compute(int b, int n)
{
    if(array[b][n] >= 0)
        return array[b][n];

    bigint sum  = 0;

    if(n == 1) sum = b;
    else if (b==1) sum = 1;
    else if (n==0 || b ==0) sum = 0;
    else
    {
        for(int i=0; i<b; i++)
            sum += compute(b-i,n-1);
    }

    array[b][n] = sum;

    return array[b][n];



}


int main()
{
    int t;
    scanf("%d",&t);
    //int k=sizeof(array)/sizeof(int);
    //int i;

    memset(array,-1,sizeof(array));

   //for(i=0;i<k;i++)
   //{
      // array[i]=-1;
 //  }

    while(t--)
    {
        int c,n;
        cin>>c>>n;

        bigint res = compute(10,n);

        printf("%d %lld\n",c,res);

    }
}
