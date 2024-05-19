#include<cstdio>
using namespace std;

int main()
{
    printf("Ready\n");
    while(1)
    {
        char a,b;
        scanf("%c%c",&a,&b);
        getchar();
        if(a==' ' && b==' ') break;

        if(a=='p'&&b=='q' || a=='q'&&b=='p'|| a=='b' && b=='d' || a=='d' && b=='b')
        printf("Mirrored pair\n");

        else printf("Ordinary pair\n");
    }
    return 0;
}
