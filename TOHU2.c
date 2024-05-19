#include<stdio.h>

int main()
{
    int t,num,i;
    char ch[100],c,enter;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<99;i++)
        {
            scanf("%d",&num);
            scanf(" %c",&c);
            ch[num]=c;
        }
        int flag=1,j;
        for(j=18;j<=81;j+=9)
        {
            if(ch[j]!=ch[9])
            flag=0;
        }

        if(flag==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
