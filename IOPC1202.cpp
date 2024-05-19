#include<cstdio>
#include<cmath>
#include<algorithm>
#define MOD 100000007
using namespace std;

int main()
{
    int t;
    long long temp;
    long long x1,x2,x3,x4;
    long long y1,y2,y3,y4;
    long long val1,val2,val3,val4,min_val;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&x1,&y1);
        scanf("%lld %lld",&x2,&y2);
        scanf("%lld %lld",&x3,&y3);
        scanf("%lld %lld",&x4,&y4);

        val1 = pow(x2-x1,2)+pow(y2-y1,2);
        val2 = pow(x3-x2,2)+pow(y3-y2,2);
        val3 = pow(x4-x3,2)+pow(y4-y3,2);
        val4 = pow(x1-x4,2)+pow(y1-y4,2);

        min_val = min(val1,val2);
        min_val=min(min_val,val3);
        min_val=min(min_val,val4);
        //printf("%\nmin=%lld\n",min_val);

        //printf("%lld %lld %lld %lld\nmin=%lld\n",val1,val2,val3,val4,min_val);

        if (val1 != min_val) //x1,x2 is a diagonal
        {
            temp=x2;
            x2=x3;
            x3=temp;
            temp=y2;
            y2=y3;
            y3=temp;
            val1 = pow(x2-x1,2)+pow(y2-y1,2);
            val2 = pow(x3-x2,2)+pow(y3-y2,2);
            val3 = pow(x4-x3,2)+pow(y4-y3,2);
            //printf("\n\n%d %d %d %d\n\n",x1,x2,x3,x4);
            //printf("\n\n%d %d %d %d\n\n",y1,y2,y3,y4);
        }

        if(val2 != min_val) //x2,x3 (new ones) is a diagonal
        {
            temp=x3;
            x3=x4;
            x4=temp;
            temp=y3;
            y3=y4;
            y4=temp;
            //printf("\n\n%d %d %d %d\n\n",x1,x2,x3,x4);
            //printf("\n\n%d %d %d %d\n\n",y1,y2,y3,y4);
        }

        //printf("\n\n%d %d %d %d\n\n",x1,x2,x3,x4);
        //printf("\n\n%d %d %d %d\n\n",y1,y2,y3,y4);



        double res_x = (double)(2*x1-2*x3+4*x2)/4;
        double res_y = (double)(2*y1-2*y3+4*y2)/4;

        if(ceil(res_x)==floor(res_x) && ceil(res_y)==floor(res_y))
        {
            printf("%lld\n", 2*min_val % MOD) ;
        }

        else
            printf("0\n");

    }
    return 0;
}
