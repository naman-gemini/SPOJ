#include<cstdio>
#define N 100005
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;
int vis[N];
int cnt;
int n;
vector<int> adj[N];
bool marked[N];

void dfs(int v)
{
    marked[v] = true;
    int sz = adj[v].size();
    for(int j=0;j<sz;j++)
        if(!marked[adj[v][j]])
        {
            dfs(adj[v][j]);
        }
}

int main()
{
    int t,e;
    scanf("%d",&t);

    while(t--)
    {
        cnt = 0;
        memset(marked,false,sizeof marked);
        int a,b;
        scanf("%d",&n);

        for(int i=0;i<n;i++) adj[i].clear();
        scanf("%d",&e);

        for(int i=0; i<e; i++)
        {
            scanf("%d %d",&a,&b);

            adj[a].push_back(b);
            adj[b].push_back(a);

        }

        for(int i=0;i<n;i++)
        {
            if(!marked[i])
            {
                dfs(i);
                cnt++;
            }
        }

        cout<<cnt<<endl;


    }

    return 0;
}
