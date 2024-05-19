#include<cstdio>
#include<queue>
#include<algorithm>
#define INF 1e+9

using namespace std;
int M,N,sx,sy,tx,ty;
typedef pair<int,pair<int,int> > iii;
int  T[222][222];
bool visited[222][222];

bool operator >(const iii &a, const iii &b){
    return a.first < b.first;
}

bool exists(int x,int y){
    if(x>=0 && x<M && y>=0 && y<N)
        if(!visited[x][y]) return true;
    return false;
}

void djikstra(int cs){
    priority_queue<iii,vector<iii>,greater<iii> > q;
    int ans[22][22];
    int d,x,y;
    for(int i=0;i<=M;i++) for(int j=0;j<=N;j++) ans[i][j]=INF,visited[i][j]=false;
    ans[tx][ty]=0;
    iii start,curr; start.first=0; start.second.first=tx; start.second.second=ty;
    q.push(start);
    while(!q.empty()){
        curr=q.top(); q.pop();
        d=curr.first; x=curr.second.first; y=curr.second.second;
        //printf("%d %d %d\n",d,x,y);
        visited[x][y]=true;
        for(int i=-1;i<=1;i+=2)
            if(exists(x+i,y) && T[x+i][y]-T[x][y]>=0)
                if( ans[x+i][y] > max(T[x+i][y]-T[x][y],ans[x][y]) )
                    ans[x+i][y]= max(T[x+i][y]-T[x][y],ans[x][y]),q.push(iii( max(T[x+i][y]-T[x][y],ans[x][y]),make_pair(x+i,y)));


        for(int i=-1;i<=1;i+=2)
            if(exists(x,y+i) and T[x][y+i]-T[x][y]>=0)
                if(ans[x][y+i] > max(T[x][y+i]-T[x][y],ans[x][y]) )
                    ans[x][y+i]= max(T[x][y+i]-T[x][y],ans[x][y]),q.push(iii( max(T[x][y+i]-T[x][y],ans[x][y]),make_pair(x,y+i)));
        }
    int res=INF;
    for(int i=0;i<M;i++){
        if(ans[i][0]<res) res=ans[i][0];
        if(ans[i][N-1] < res) res=ans[i][N-1];
    }
    for(int i=0;i<N;i++){
        if(ans[0][i]<res ) res=ans[0][i];
        if(ans[M-1][i]<res) res=ans[M-1][i];
    }

    if(res < INF){
        printf("%d. %d\n",cs,res);
    }
    else
        printf("%d. IMPOSSIBLE\n",cs);
}



void make_graph(){
    scanf("%d%d",&M,&N);
    scanf("%d%d",&tx,&ty);
    tx--; ty--;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&T[i][j]);


}



int main(){
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        make_graph();
        djikstra(cs);
    }
    return 0;
}



