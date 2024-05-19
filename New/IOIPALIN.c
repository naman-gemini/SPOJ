#include<stdio.h>
#include<ctype.h>
int dp[5005][5005];
char s[5005],r[5005];

int main(){
    int size,i,j;
    char c;
    scanf("%d",&size);
    while(isspace(c=getchar()));

    for(i=0;i<size;i++){
        s[i]=c;
        c=getchar();
    }

    dp[0][0]=0;
    //printf("%s\n",s);
    for(i=size-1,j=0;i>=0;i--,j++)r[j]=s[i];
    //printf("%s\n",r);

    for(i=1;i<=size;i++)
        for(j=1;j<=size;j++){
            if(s[i-1]==r[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else if(dp[i][j-1] > dp[i-1][j])
                dp[i][j]=dp[i][j-1];
            else
                dp[i][j]=dp[i-1][j];

        }
    printf("%d\n",size-dp[size][size]);
    return 0;
}

