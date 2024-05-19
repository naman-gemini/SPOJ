#include<cstdio>
#include<cstring>
long long ans=0;

int N,K,S,D;

long long dp[64][64];

long long solve(int n,int k){
    if(k==K) return n==D;
    if(dp[n][k] !=-1 ) return dp[n][k]; ///It has already been memoized.
    dp[n][k]=0;
    int u=n+1;
    int v=n-1;
    if(u==N) u=0;
    if(v==-1)  v=N-1;
    dp[n][k]= solve(u,k+1)+solve(v,k+1);

    return dp[n][k];
}



int main(){

    while(scanf("%d%d",&N,&K)==2){
        if(N==-1 || K==-1) break;
        scanf("%d%d",&S,&D);
        S--;D--;
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(S,0));


    }

    return 0;
}
