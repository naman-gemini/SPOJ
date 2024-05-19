#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int case_no=1;case_no<=t;case_no++)
    {
        int m,k;
        scanf("%d %d",&m,&k);
        printf("Case #%d: %.8lf\n",case_no,1/((double)k+m*k+1));
    }
    return 0;
}
