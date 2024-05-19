#include<cstdio>
#include<algorithm>
using namespace std;

int time[]= {0,1*60+6,2*60+11,3*60+17,4*60+22,5*60+28,6*60+33,7*60+39,8*60+44,9*60+50,10*60+55,12*60,
               13*60+6,14*60+11,15*60+17,16*60+22,17*60+28,18*60+33,19*60+39,20*60+44,21*60+50,22*60+55};


int main()
{
    int t,a,b,x,c,d,y;
    int ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d:%d",&a,&b);
        scanf("%d:%d",&c,&d);
        a*=60;
        x=(a+b);
        c*=60;
        y=(c+d);
        for(int i=x+1;i<=y;i++) if(binary_search(time,time+22,i)) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
