#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
vector<ull> fib;
int times[50];
//vector<ull> ans;
vector<ull>::iterator it;

int main()
{
    int n,temp;
    fib.push_back(0);
    fib.push_back(1);
    for(int i=2;i<50;i++) fib.push_back(fib[i-1]+fib[i-2]);
    while(scanf("%d",&n) && n!=0)
    {
        while(n--)
        {
            int val;
            scanf("%d",&val);
            it=lower_bound(fib.begin(),fib.end(),val);
            if((*it-val)>(val-*(it-1)))
            {
                times[int(it-1-fib.begin())]++;
            }
            else
            {
                times[int(it-fib.begin())]++;
            }

        }
        it=fib.begin();
        for(int i=0;i<50;i++,it++)
        {
            temp=times[i];
            while(temp--) printf("%d ",*it);
        }
        printf("\n");
        for(int i=0;i<50;i++) times[i]=0;
    }
    fib.clear();
    return 0;
}
