#include<cstdio>
#include<cstdlib>
#include<iostream>
#define mod 1000000009
using namespace std;

typedef long long ll;
int a[50005];

ll modular_pow(ll base,ll exponent)
{
    ll result=1;
    while(exponent>0)
    {
        if((exponent&1)==1)
        {
            result=(result*base)%mod;
        }
        exponent = exponent >> 1;   //divide by 2
        base=(base*base)%mod;
    }
    return result;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        //int *a;
        //a=(int*)malloc(n*sizeof(int));

        long long int num_sets,sum=0,res;
        int num_pos=0,num_neg=0,num_zero=0;

        for(int i=0;i<n;i++)
        {

            scanf("%d",&a[i]);

            if(a[i]<0)
            {
                num_neg++;
                //cout<<"NAMAN1"<<endl;
            }
            if(a[i]==0)
            {
                num_zero++;
                //cout<<"NAMAN2"<<endl;
            }
            if(a[i]>0)
            {
                num_pos++;
                sum+=a[i];
                //cout<<"NAMAN3"<<endl;
            }
        }

        //if(num_neg==0 && num_zero==0)
        if(num_neg==0 && num_pos==0)
        {
            res=0;
            num_sets=modular_pow(2,num_zero);
            num_sets--;
        }

        else if(num_neg==0)
        {
            res=sum;
            if(num_zero>0)
            {
                num_sets=modular_pow(2,num_zero);
            }
        }

        else
        {
            if(num_pos==0)
            {
                if(num_zero>0)
                {
                    num_sets=modular_pow(2,num_zero)-1;
                    res=0;
                }
                else
                {
                    int max = a[0];
                    for(int i=0;i<n;i++)
                    {
                        if(a[i]>max)
                        {
                            max=a[i];
                        }
                    }
                    num_sets=0;
                    for(int i=0;i<n;i++)
                    {
                        if(a[i]==max)
                        {
                            num_sets++;
                            //num_sets=num_sets%mod;
                        }
                    }
                    res=max;
                }
            }

            else
            {
                //all gen case
                res=0;
                num_sets=1;
                for(int i=0;i<n;i++)
                {
                    if(a[i]>0)
                    res+=a[i];
                }
                if(num_zero > 0)
                {
                    num_sets=modular_pow(2,num_zero);
                }
            }
            //free(a);
        }

        printf("%lld %lld\n",res,num_sets);

    }
    return 0;
}
