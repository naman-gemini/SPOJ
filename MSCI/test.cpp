#include <cstdio>
#include <algorithm>
using namespace std;

bool comp(const int &a,const int &b)
{
    return a<b;
}

int main()
{
    int a[10],n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n,comp);
    for(int i=0; i<n; i++) printf("%d ",a[i]);
    return 0;
}
