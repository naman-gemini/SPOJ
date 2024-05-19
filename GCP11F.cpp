#include<stdio.h>
#include<string.h>

int main()
{

    int t,i,max,d;
    char s[1005],result;
    scanf("%d\n",&t);

    while(t--)
    {
        int counter=0;
        result=0;
        max=0;
        gets(s);

        int a[27] = {0};

        for(i=0; i<strlen(s); i++)
        {
            if(s[i]!=' ')
            {
                a[s[i]-65]++;
                if(a[s[i]-65] > max)
                {
                    max=a[s[i]-65];
                    result=s[i];
                }
            }
        }

        for(i=0;i<27;i++)
        {
            if(a[i]==max)
            counter++;
        }
        if(counter > 1)
        {
            printf("NOT POSSIBLE\n");
            continue;
        }

        if(result >= 'E')
        {
            d=result-'E';
            for(i=0; i<strlen(s); i++)
            {
                if(s[i]!=' ')
                {
                s[i]-=d;
                    if(s[i]<65)
                    {
                        s[i]+=26;
                    }
                }
            }
        }

        else
        {
            d=result-'E';
            for(i=0; i<strlen(s); i++)
            {
                if(s[i]!=' ')
                {
                    s[i]+=-d;
                    if(s[i]>90)
                    {
                        s[i]-=26;
                    }
                }
            }
        }
        if(d<0) d=26+d;
        printf("%d ",d);
        printf("%s\n",s);
    }
    return 0;
}
