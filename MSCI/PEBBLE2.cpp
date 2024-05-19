#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[1005];
    int cas=1;
    while(scanf("%s",s)!=EOF)
    {
        int count=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]=='1')
            {
                for(int j=i;j<len;j++)
                {
                    if(s[j]=='0') s[j]='1';
                    else s[j]='0';
                }
                count++;
            }
        }
        printf("Game #%d: %d\n",cas++,count);
    }
    return 0;
}
