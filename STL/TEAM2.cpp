#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int a,b,c,d;
    vector<int> v;
    int count=0;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
    {
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        sort(v.begin(),v.end());
        count++;
        int i;
        int x=*(v.end()-1);
        int y=*(v.end()-2);
        v.erase(v.begin(),v.end());
        printf("Case %d: %d\n",count,x+y);
    }
    return 0;
}
