#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    typedef unsigned long long int ll;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll x,y,z,D,w;
        ll root1;
        scanf("%lld %lld %lld",&x,&y,&z);
        D=(x*x+(y+2*z)*y);
        w=ll(sqrtl(D));
        //printf("D=%lld sqrt(D)=%lf int value=%lld\n",D,sqrt(D),w);
        if(w*w!=D) {printf("Not this time.\n"); continue;}
        //D=(ll)(sqrt(x*x+(y+2*z)*y));
        root1 = (z*(x+w)/(y+2*z));
        //if(((z*(x+w))%(y+2*z))==0 && ((z*(x-w))%(y+2*z))==0) {printf("Not this time.\n");continue;}
        if(((z*(x+w))%(y+2*z))==0 && root1<=x) {printf("%lld\n",root1);continue;}
        printf("Not this time.\n");
    }
    return 0;
}

