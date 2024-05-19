#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;

int main()
{
    int t,a,b,n,sum,max,maxi,maxj,summin;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        for(int i=0; i<a; i++)
        {
            scanf("%d",&n);
            v.push_back(n);
        }
        max=-1,maxi=0,maxj=0,summin=100000000;

        for(int i=0; i<a; i++)
        {
            sum=0;
            for(int j=i; j<a; j++)
            {
                if(sum+v[j]<=b)
                {
                    sum+=v[j];
                    //printf("sum=%d\n",sum);
                    if(j-i+1>max)
                    {
                        max=j-i+1;
                        maxi=i;
                        maxj=j;
                        summin=sum;
                    }
                    else if(j-i+1==max)
                    {
                        if(sum<summin)
                        {
                            max=j-i+1;
                            maxi=i;
                            maxj=j;
                        }
                    }
                }
                else break;
            }
        }
        sum=0;
        for(int i=maxi; i<=maxj; i++) sum+=v[i];
        printf("%d %d\n",sum,max);
        v.clear();
    }
    return 0;
}
