#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t;
    char a[55];
    scanf("%d\n",&t);
    //getchar();
    while(t--)
    {
        scanf("%s",a);
        bool flag=false;
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]=='D')
            {
                flag=true;
                break;
            }
        }
        if(flag)
        printf("You shall not pass!\n");
        else
        printf("Possible\n");
    }
    return 0;
}
