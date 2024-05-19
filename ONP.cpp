#include<cstdio>
#include<cctype>
#include<stack>
#include<queue>
using namespace std;

stack<char> s;
queue<char> q;

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        while(!s.empty()) s.pop();
        while(!q.empty()) q.pop();

        char c;
        while((c=getchar())!='\n')
        {
            if(isalpha(c)) q.push(c);
            if(!isalpha(c) && c!=')') s.push(c);
            if(c==')')
            {
                while(s.top()!='(')
                {
                    q.push(s.top());
                    s.pop();
                }
                s.pop();
            }
        }

        while(!q.empty())
        {
            printf("%c",q.front());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}
