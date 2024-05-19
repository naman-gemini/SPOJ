#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

vector<bool> v;

void binary(ll n)
{
    int a;
    while(n)
    {
        a=(n%2);
        v.push_back(a);
        n=n/2;
    }
}

int main()
{
    int t;
    ll n;
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        flag=true;
        v.clear();
        scanf("%lld",&n);

        if(n%2==0)
            printf("Marica\n");
        else
        {
            binary(n);
            for(int i=2; i<v.size(); i+=2)
                if(v[i]==1)
                {
                    flag=false;
                    break;
                }
            if(flag)
                printf("Ivica\n");
            else
                printf("Marica\n");
        }

    }
    return 0;
}
