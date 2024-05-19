#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    typedef long long int ll;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll x,y,z,D,w;
        ll check1,check2;
        scanf("%lld %lld %lld",&x,&y,&z);
        if(x==0)
        {
            printf("0\n");
            continue;
        }
        D=(x*x+(y+2*z)*y);
        w=ll(sqrtl(D));
        //printf("D=%lld sqrt(D)=%lf int value=%lld\n",D,sqrt(D),w);
        if(w*w!=D) {printf("Not this time.\n"); continue;}
        //D=(ll)(sqrt(x*x+(y+2*z)*y));
        check1 = ((x+w)/(y+2*z))*z;
        check2 = ((x-w)/(y+2*z))*z;
        //printf("check1=%lld check2=%lld\n",check1,check2);
        if(((z*(x+w))%(y+2*z))==0 && ((z*(x-w))%(y+2*z))==0 && check1==check2) {printf("%lld\n",check1);continue;}
        if(((z*(x+w))%(y+2*z))==0 && ((z*(x-w))%(y+2*z))==0) {printf("Not this time.\n");continue;}
        if(((z*(x+w))%(y+2*z))==0 && check1>=0 && check1<=x) {printf("%lld\n",check1);continue;}
        printf("Not this time.\n");
    }
    return 0;
}
