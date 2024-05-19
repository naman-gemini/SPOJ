#include<cstdio>
#include<cstring>
#include<cstdlib>
int main()
{
    char string[1005];
    //string=(char *)malloc(10*sizeof(char));
    int cas=0,i,count,len;
    while(scanf("%s",string)!=EOF)
    {
        count=0;
        len=strlen(string);
        i=len-1;
        while(i>=0)
        {
            if(string[i]=='1')
            {
                while(string[i]=='1')
                    i--;
                count++;
            }
            if(string[i]=='0')
            {
                if(i>=0)
                {
                    if(string[i-1]=='1')
                    {
                        i--;
                        count+=2;
                    }
                }
            }
            i--;
        }
        cas++;
        printf("Game #%d: %d\n",cas,count);
    }
    return 0;
}

