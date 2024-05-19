#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main()
{
    int a,b,c;

    while(scanf("%d %d %d",&a,&b,&c) ==3)
    {
        if(a==0 || b==0 || c==0) break;
        v.clear();
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());

        if((v[0] * v[0]) + (v[1] * v[1]) == (v[2]*v[2]))
            printf("right\n");
        else printf("wrong\n");
    }


    return 0;
}
