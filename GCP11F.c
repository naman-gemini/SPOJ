#include<stdio.h>
#include<string.h>

int main()
{
    int t,i,a[26],max,d;
    char s[1005],result;
    scanf("%d",&t);
    while(t--)
    {
        result=0;
        max=0;
       // for(i=0;;i++)
       // scanf("%s",&s[i]);
        gets(s);
        puts(s);
        printf("%c",s[0]);

       /* for(i=0;i<strlen(s);i++)
        printf("%s\n",s);

        for(i=0;i<strlen(s);i++)
        {
            a[s[i]]++;
            if(a[s[i]] > max)
            {
                max=a[s[i]];
                result=s[i];
            }
        }

        for(i=0;i<26;i++)
        printf("%d\n",a[i]);


        if(result >= 'E')
        {
            d=result-'E';
            for(i=0;i<strlen(s);i++)
            s[i]-=d;
        }

        else
        {
            d=26-(result-'E');
            for(i=0;i<strlen(s);i++)
            s[i]+=26-d;
        }

        if(d>=0 && d<=25) printf("%d ",d);

        for(i=0;i<strlen(s);i++)
        printf("%s\n",s);*/
    }
    return 0;
}
