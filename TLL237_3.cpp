#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int segment[1024][2];
int value[1024];

void insert(int x,int val, int i=0,int l=0,int r=512)
{
    if (l+1>=r)
    {
        segment[i][0]=x;
        value[x]=val;
        return;
    }
    int m=(l+r)/2;

    if (x<m)
        insert(x,val, i*2+1,l,m);
    else
        insert(x,val, i*2+2,m,r);

    // find the indices of the 2 smallest children (out of 4)
    int low[4] = {segment[i*2+1][0],segment[i*2+2][0],segment[i*2+1][1],segment[i*2+2][1]};

    // hacky sorting
    if (low[0]<0 or low[1]>=0 and value[low[0]]>value[low[1]]) swap(low[0],low[1]);
    if (low[2]<0 or low[3]>=0 and value[low[2]]>value[low[3]]) swap(low[2],low[3]);
    if (low[1]<0 or low[2]>=0 and value[low[1]]>value[low[2]]) swap(low[1],low[2]);

    segment[i][0] = low[0];
    segment[i][1] = low[1];
}

int index_lowest(bool most)
{
    return segment[0][most];
}

int main()
{
    for (int i=1024; i--;) segment[i][0]=segment[i][1]=-1;

    insert(3,1);
    insert(2,2);
    insert(1,3);
    insert(0,4);
    insert(50,0);

    printf("%d, %d\n",index_lowest(0),index_lowest(1));
}
