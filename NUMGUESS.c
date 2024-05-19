#include<stdio.h>
#include<string.h>

int main()
{
    int a,b;
    char s[5];
    scanf("%d %d",&a,&b);
    int mid,min=a,max=b;
    while(1)
    {
        mid=(min+max)/2;
        printf("%d\n",mid);
        fflush(stdout);
        scanf("%s",s);
        if(!strcmp(s,"WIN")) return 0;
        else if(!strcmp(s,"LOW"))
        {
            min=mid+1;
        }
        else if(!strcmp(s,"HIGH"))
        {
            max=mid-1;
        }

    }
    return 0;
}
