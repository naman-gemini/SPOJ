#include<stdio.h>
#include<string.h>

int main()
{
    int t,i,max,j;
    char size[10][105];
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        max=0;
        for(i=0;i<10;i++)
        {
           gets(size[i]);
           printf("%c  ",size[i][strlen(size[i])-1]);
           printf("%d",(int)(size[i][strlen(size[i])-1])+250);
           if(max<(int)((size[i][strlen(size[i])-1])-48))
           max=(int)(size[i][strlen(size[i])-1]-48);
        }
        printf("Case #%d:\n",j);
        for(i=0;i<10;i++)
        {
            if( (int)(size[i][strlen(size[i])-1] - 48) == max)
            {
                printf("%s\n",size[i]);
            }
        }

    }
    return 0;
}
