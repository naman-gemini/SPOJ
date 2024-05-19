#include <cstdio>
#include <string>
#include <iostream>
//#include <algorithm>
using namespace std;

int min (int a, int b)
{
    if(a<b) return a;
    else return b;
}

int max (int a, int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int t,i=0,j=0,count=0,min_val,k=0;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        // input taking
        cin>>s;
        if(s=="1/4")
            j++;
        else if(s=="3/4")
            k++;
        else if(s=="1/2")
            i++;
    }

    while(i!=0||j!=0||k!=0)
    {
        //making 3/4 and 1/4 pairs
        if(j!=0)
        {
            if(k!=0)
            {
                //printf("j=%d k=%d\n",j,k);

                if(j<k)
                {
                    count+=j;
                    j=0;
                    k-=count;
                }
                else
                {
                    count+=k;
                    k=0;
                    j-=count;

                }
               // printf("j=%d k=%d\n",j,k);



            }
        }

        //remaining 3/4 will result in a pizza

        if(k!=0)
        {
            count+=k;
            k=0;
        }

        //making 1/2 pairs

        if(i%2==0 && i>0)
        {
            count+=i/2;
            i=0;
        }

        if(i%2!=0 && i>1)
        {
            count+=i/2;
            i=1;
        }

        //combining 2 pairs of 1/4

        if(j>=4)
        {
            if(j%4==0)
            {
                count+=j/4;
                j=0;
            }
            else
            {
                count+=j/4;
                j%=4;
            }
        }

        if(i==1)
        {
            //pair 1/2 with 1/4
            if(j>=2)
            {
                count++;
                j-=2;
                i=0;
            }
            else
            {

                count++;
                j=0;
                i=0;
            }
        }

        if (i==0)
        {
            //pairing last set of 1/4s (<4)
            if (j!=0)
            {
                count++;
                j=0;
            }
        }

        if(j!=0)
        {
            {
                //if only 1/4's are left
                count++;
                j=0;
            }
        }


    }
    count++;
    printf("%d\n",count);
    return 0;
}
