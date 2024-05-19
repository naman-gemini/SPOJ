#include<cstdio>
using namespace std;

int main()
{
    int n;
    long long unsigned row,col,col1,col2,andd;
    int par,sum;

    while(scanf("%d",&n)==1 &&n>=0)
    {
        scanf("%llu %llu %llu",&row,&col1,&col2);
        sum=0;
        for(col=col1;col<=col2;col++)
        {
            andd=row&col;
            andd^=andd>>1;
            andd^=andd>>2;
            andd=(andd&0x1111111111111111ULL)*0x1111111111111111ULL;
            par=(int)((andd>>60)&1);
            sum+=1-2*par;
        }
        printf("%d\n",sum);
    }
    return 0;
}
