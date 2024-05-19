#include<cstdio>
#include<math.h>

double dp[128][350][11]; // this is the probability of winning


double solve(int balls,int runs,int wickets){


    if(dp[balls][runs][wickets]!= -1.0) return dp[balls][runs][wickets];
    if(runs <=0) {dp[balls][runs][wickets]=1.0; return dp[balls][runs][wickets];}
    if(balls>=120 or wickets <=0 ) {dp[balls][runs][wickets]=0.0; return dp[balls][runs][wickets];}

    //10 events
    double dot=  solve(balls+1,runs,wickets);
    double run_1=solve(balls+1,runs-1,wickets);
    double run_2=solve(balls+1,runs-2,wickets);
    double run_3=solve(balls+1,runs-3,wickets);
    double run_4=solve(balls+1,runs-4,wickets);
    double run_5=solve(balls+1,runs-5,wickets);
    double run_6=solve(balls+1,runs-6,wickets);

    double noball=solve(balls,runs-1,wickets);
    double wicket=solve(balls+1,runs,wickets-1);

    dp[balls][runs][wickets]=(dot+run_1+run_2+run_3 +run_4+run_5+run_6+ 2*noball+wicket)/10.0;

    return dp[balls][runs][wickets];


}

int main(){
    int t;
    int x,y,balls,reqdruns,target,wickets,runs;
    double ans;
    scanf("%d\n",&t);
     for(int i=0;i<128;i++) for(int j=0;j<350;j++) for(int k=0;k<11;k++) dp[i][j][k]=-1.0;
    while(t--){

        scanf("%d.%d %d/%d %d",&x,&y,&runs,&wickets,&target);
        balls=x*6+y;
        wickets=10-wickets;

        reqdruns=target-runs;
        ans=solve(balls,reqdruns,wickets);
        ans*=10000;
        ans=floor(ans)/100;
        printf("%.2lf\n",ans);

    }
    return 0;
}


