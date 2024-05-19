#include<cstdio>
#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;

vector<int> L;
vector<int> S;
vector<int> v[10005];
int indeg[10005];

void calculate_indegree(int n)
{
	for(int i=1;i<=n;i++)
	{
		int x=v[i].size();
		for(int j=0;j<x;j++)
		{
			indeg[v[i][j]]++;
		}
	}
}

void print_indeg(int n)
{
    for(int i=1;i<=n;i++) printf("%d ",indeg[i]);
    printf("\n");
}

void populate(int n)
{
	calculate_indegree(n);
	//print_indeg(n);
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0) S.push_back(i);
	}
}

void print_graph(int n)
{
	for(int i=1;i<=n;i++)
	{
	    printf("v[%d]=>",i);
		for(int j=0;j<v[i].size();j++)
		{
			printf("%d, ",v[i][j]);
		}
		printf("\n");
	}
}

void printS()
{
    for(int i=0;i<S.size();i++) printf("%d ",S[i]);
}

bool no_other_incoming_edges(int a)
{
    return indeg[a]==0;
}

void topological_sort()
{
    while(!S.empty())
    {
    	sort(S.rbegin(),S.rend());
        int n=S.back();
        L.push_back(n);
        S.pop_back();
        int x=v[n].size();
        for(int i=0;i<x;i++)
        {
            if(v[n][i]!=-1) //the edge still exists;
            {
                int temp=v[n][i];
                v[n][i]=-1; //remove the edge
                indeg[temp]--;
                if(no_other_incoming_edges(temp))
                {
                    S.push_back(temp);
                }
            }
        }
    }
}

bool graph_has_edges(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]!=0) return true;
    }
    return false;
}

void print_L()
{
	int x=L.size();
    for(int i=0;i<x;i++) printf("%d ",L[i]);
    printf("\n");
}

int main()
{
	int n,m,x,y;
	//n is number of vertices
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
	}

	populate(n);
	topological_sort();
	if(graph_has_edges(n)) printf("Sandro fails.\n");
	else print_L();
	return 0;
}
