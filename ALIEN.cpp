#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;

int main()
{
    int t,a,b,n,sum,max,summin;
    int p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        for(int i=0; i<a; i++)
        {
            scanf("%d",&n);
            v.push_back(n);
        }
        p=0,q=0;
        sum=0;
        summin=0;
        max=0;

        while(p<a && q<a)
        {
            if(p>q)
            {
                q=p;
                sum=0;
            }
            if(sum+v[q]<=b)
            {
                sum+=v[q];
                q++;
            }
            else
            {
                if(!v.empty())
                {
                    sum-=v[p];
                }
                p++;
            }
            if(q-p+1>max)
            {
                max=q-p+1;
                summin=sum;
            }
            else if(q-p+1==max)
            {
                if(sum<summin)
                    summin=sum;
            }
        }
        printf("%d %d\n",summin,max-1);
        v.clear();
    }
    return 0;
}
