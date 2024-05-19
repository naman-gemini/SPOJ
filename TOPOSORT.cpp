#include<cstdio>
#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
#define DEBUG(x) printf(#x"=%d\n",x)

vector<int> v[10005];
vector<int>::iterator it;
vector<int> ans;
bool check[10005];
bool visited[10005];

void dfs(int a)
{
	visited[a]=true;
	if(v[a].empty())
	{
		if(!check[a])
		{
			ans.push_back(a);
			check[a]=true;
		}
		return;
	}
	for(int i=0; i<v[a].size(); i++)
	{
		if(!visited[v[a][i]])
		{
			dfs(v[a][i]);
		}
	}
	if(!check[a])
	{
		ans.push_back(a);
		check[a]=true;
	}
}

int main()
{
	int n,m,x,y;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
	}

	for(int i=1;i<=n;i++)
	{
		dfs(i);
	}

	for(int i=n-1; i>=0; i--)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
