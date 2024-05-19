#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main()
{
    int t,n;
    long long k;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d %lld",&n,&k);
        for(int i=n;i>0;i--)
        {
            v.push_back(k);
            k=ll(ceil((double)k/2));
        }
        reverse(v.begin(),v.end());
        bool gender=0;
        //0 is male , 1 is female
        for(vector<ll>::iterator it=v.begin();it<v.end();it++)
        {
            //if "it" points to second child, then change its gender, as male's 2nd child is female and viceversa
            if(*it == 2*(*(it-1)))
               {
                   gender=!gender;
               }
        }

        if(gender)
        {
            printf("Female\n");
        }
        else
        {
            printf("Male\n");
        }
    }
    return 0;
}
