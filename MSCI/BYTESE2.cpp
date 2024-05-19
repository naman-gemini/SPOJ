#include<cstdio>
#include<queue>
using namespace std;

priority_queue<int , vector<int> ,greater<int> > enter;
priority_queue<int , vector<int> ,greater<int> > ex;
priority_queue<int> ans;

int main()
{
    int t,n;
    int a,b;
    int count;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d",&a,&b);
            enter.push(a);
            ex.push(b);
        }

        while(!enter.empty())
        {
            if(enter.top()<ex.top())
            {
                ans.push(++count);
                enter.pop();
            }
            else
            {
                ans.push(--count);
                ex.pop();
            }
        }

        printf("%d\n",ans.top());
        ex.push(2);

        while(!ex.empty()) ex.pop();
        while(!ans.empty()) ans.pop();
    }
    return 0;
}
