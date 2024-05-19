#include<stdio.h>
#include<string.h>

int main()
{
    char c[1100];
    int i,flag;
    while(1)
    {
        flag=1;
        gets(c);
        if(c[0]=='*') return 0;

        for(i=0;i<strlen(c);i++)
        {
            if(c[i]==' ')
            {
                if(c[i+1]!=c[0] && c[i+1]!=(c[0]+32) && c[i+1]!=(c[0]-32))
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
