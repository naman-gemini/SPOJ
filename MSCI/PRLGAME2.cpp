#include<cstdio>
using namespace std;

int main()
{
    int n,p,q,case_no=1;
    while(scanf("%d %d %d",&n,&p,&q)!=EOF)
    {
        printf("Case %d: %.4lf\n",case_no++,((double)(q+1))/(p+2));
    }
    return 0;
}
