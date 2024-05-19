#include<stdio.h>
int main()
{
    int n,k,num,counter=0;
    scanf("%d",&n);
    scanf("%d",&k);
    while(n--)
    {
        scanf("%d",&num);
        if(num%k==0)
        counter++;
    }
    printf("%d\n",counter);
    return 0;
}
