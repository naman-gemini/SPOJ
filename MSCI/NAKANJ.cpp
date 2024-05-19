#include<cstdio>
#include<cmath>
#include<algorithm>
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;

int solve(int a,int b)
{
    if(a==1 && b==0) return 3;
    if(a==2 && b==2) return 4;
    int delta=a-b;
    if(b>delta) return 2*(ceil((b-delta)/3.0))+delta;
    else
    return delta-2*((delta-b)/4);
}

int main()
{
    int x,y,t;
    char a,b,c,d;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        a=getchar();
        b=getchar();
        getchar();
        c=getchar();
        d=getchar();
        getchar();

        //printf("a=%c b=%c c=%c d=%c\n",a,b,c,d);

        if(a=='a' && b=='1' && c=='b' && d=='2')
        {
            printf("4\n");
            continue;
        }
        if(a=='b' && b=='2' && c=='a' && d=='1')
        {
            printf("4\n");
            continue;
        }
        if(a=='g' && b=='7' && c=='h' && d=='8')
        {
            printf("4\n");
            continue;
        }
        if(a=='h' && b=='8' && c=='g' && d=='7')
        {
            printf("4\n");
            continue;
        }
        if(a=='a' && b=='8' && c=='b' && d=='7')
        {
            printf("4\n");
            continue;
        }
        if(a=='b' && b=='7' && c=='a' && d=='8')
        {
            printf("4\n");
            continue;
        }
        if(a=='g' && b=='2' && c=='h' && d=='1')
        {
            printf("4\n");
            continue;
        }
        if(a=='h' && b=='1' && c=='g' && d=='2')
        {
            printf("4\n");
            continue;
        }


        x=int(a-c);
        if(x<0) x=-x;
        //x++;
        y=(b-d);
        if(y<0) y=-y;
        //y++;

        //DEBUG(x);
        //DEBUG(y);

        if(y>x) swap(x,y);

        printf("%d\n",solve(x,y));
    }
    return 0;
}
