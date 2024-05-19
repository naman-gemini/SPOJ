#include <cstdio>
using namespace std;

int main()
{
    char a[16], b[16];
    int cs=1,x;
    while(scanf("%s %s", a, b) == 2)
    {
        if(!a[1]) printf("Case %d: UNIQUE\n", cs++);
        else
        {
            if(a[1]=='b')
            {
                a[1]='#';
                x=-1;
            }
            else
            {
                a[1]='b';
                x=1;
            }

            //music notation conversion
            a[0]=(a[0]-'A'+7+x)%7+'A';
            printf("Case %d: %s %s\n", cs++, a, b);
        }
    }
    return 0;
}
