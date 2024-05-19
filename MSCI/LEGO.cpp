#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct block
{
    int xmax,ymax,xmin,ymin;
    int idx;
};

vector<int> edges[111111];
int B,cc=0;
bool visited[111111];
block top[111111],bottom[111111];

bool cmp1(const block &a, const block &b)
{
    if(a.ymax==b.ymax)
        return a.xmax < b.xmax;
    return a.ymax<b.ymax;
}

bool cmp2(const block &a, const block &b)
{
    if(a.ymin==b.ymin)
        return a.xmax < b.xmax;
    return a.ymin<b.ymin;
}

void make_graph()
{
    sort(bottom,bottom+B,cmp1);
    sort(top,top+B,cmp2);
    int i=0,j=0;
    while(i<B && j<B)
    {
        if(bottom[i].ymax < top[j].ymin) i++;
        else if(bottom[i].ymax > top[j].ymin) j++;
        else
        {
            if(top[j].xmin >= bottom[i].xmax) i++;
            else if(top[j].xmax <= bottom[i].xmin) j++;
            else
            {
                //printf("connection: %d %d\n",bottom[i].idx,top[j].idx);
                edges[bottom[i].idx].push_back(top[j].idx);
                edges[top[j].idx].push_back(bottom[i].idx);
                if(bottom[i].xmax > top[j].xmax) j++;
                else if(bottom[i].xmax < top[j].xmax) i++;
                else
                {
                    i++;
                    j++;
                }
            }
        }
    }
}

void dfs(int v)
{
    visited[v]=true;
    for(int i=0; i<edges[v].size(); i++)
        if(!visited[edges[v][i]])
            dfs(edges[v][i]);
}

void count_connected()
{
    for(int i=0; i<B; i++)
        if(!visited[i])
        {
            cc++;
            dfs(i);
        }
}



int main()
{
    scanf("%d",&B);
    for(int i=0; i<B; i++)
    {
        scanf("%d%d%d%d",&bottom[i].xmin,&bottom[i].ymin,&bottom[i].xmax,&bottom[i].ymax);
        top[i].xmin=bottom[i].xmin,top[i].ymin=bottom[i].ymin,top[i].xmax=bottom[i].xmax,top[i].ymax=bottom[i].ymax;
        top[i].idx=bottom[i].idx=i;
    }
    make_graph();
    count_connected();
    printf("%d\n",cc);


}
