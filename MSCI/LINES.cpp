#include<cstdio>
#include<iostream>
#include<set>
using namespace std;

struct point
{
    int x;
    int y;
};

struct point pt[200];

set<double> s;

int main()
{
    int t;
    double slope;
    while(scanf("%d",&t) && t!=0)
    {
        s.clear();
        for(int i=0;i<t;i++) scanf("%d %d",&pt[i].x,&pt[i].y);

        for(int i=0;i<t-1;i++)
        for(int j=i+1;j<t;j++)
        {
            if(pt[j].x-pt[i].x==0) slope=1.732;
            else slope=(double)(pt[j].y-pt[i].y)/(pt[j].x-pt[i].x);
            s.insert(slope);
        }
        printf("%d\n",s.size());
    }
    return 0;
}
