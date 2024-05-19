#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    int r,k,x,y;
    start:
    while(cin>>n)
    {
        if(n==1)
        {
            printf("0 0\n");
            goto start;
        }
        r=0;
        k=1;

        while(n>k)
        {
            r++;
            k+=r*6;                     //r has the ring number now, k is last elemnt in ring
        }

        x=r;
        y=0;

        if(k==n)
        {
            printf("%d %d\n",x,y);
            goto start;
        }

        while(x!=-y)
        {
            y--;
            k--;
            if(k==n)
            {
                printf("%d %d\n",x,y);
                goto start;
            }
        }

        while(x!=0)
        {
            x--;
            k--;
            if(k==n)
            {
                printf("%d %d\n",x,y);
                goto start;
            }
        }

        while(y!=0)
        {
            y++;
            x--;
            k--;
            if(k==n)
            {
                printf("%d %d\n",x,y);
                goto start;
            }
        }

        while(x!=-y)
        {
            y++;
            k--;
            if(k==n)
            {
                printf("%d %d\n",x,y);
                goto start;
            }
        }

        while(x!=0)
        {
            x++;
            k--;
            if(k==n)
            {
                printf("%d %d\n",x,y);
                goto start;
            }
        }

        while(x+y==r)
        {
            x++;
            y--;
            k--;
             if(k==n)
            {
                printf("%d %d\n",x,y);
                goto start;
            }
        }
    }
    return 0;
}
