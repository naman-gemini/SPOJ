#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        vector<int> v;
        vector<int>::iterator it;

        int val,count=0,min;
        for(int i=0; i<t; i++)
        {
            scanf("%d",&val);
            v.push_back(val);
        }

        while(v.size()>0)
        {
            int max_val=*max_element(v.begin(),v.end());
            min=max_val;
            count++;

            for(it=v.begin(); it<v.end(); it++)
            {
                if(*it<min) min=*it;

                if(*it==max_val)
                {
                    if(min<*it)
                    count++;
                    v.erase(v.find(v.begin(),v.end(),max_val));
                    break;
                }
            }

        }
         printf("%d\n",count);
    }
    return 0;
}
