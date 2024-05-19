#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
typedef long long ll;
stack<ll> mystack;

void bin(ll a)
{
    while(a)
    {
        ll rem,q;
        rem=a%2;
        mystack.push(rem);
        q=a/2;
        a/=2;
    }
}

void empty_stack()
{
    while(!mystack.empty())
    {
        mystack.pop();
    }
}

ll items_in_stack(stack<ll> a)
{
    ll count=0;
    while(!a.empty())
    {
        a.pop();
        count++;
    }
    return count;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        empty_stack();
        ll a,n=1,x=0;
        scanf("%lld",&a);
        while(x<a)
        {
            x=pow(2,n+1)-2;
            n++;
        }
        n--;
        //n here is the number of digits that I have to use
        ll diff=a-pow(2,n)+2;
        diff--;
        //printf("n=%d diff=%d\n",n,diff);
        bin(diff);
        ll items=items_in_stack(mystack);
        for(int i=0; i<n; i++)
        {
            if(i>=n-items)
            {
                if(mystack.top()==1)
                    printf("6");
                else printf("5");
                mystack.pop();
            }
            else
                printf("5");
        }
        printf("\n");
    }
    return 0;
}
