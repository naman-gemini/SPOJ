#include<cstdio>
#include<queue>
 
using namespace std;
typedef pair<int,int> ii;
struct allow{
    int n,s,e,w;
};
 
struct allow allowed[111][111];
int ans[111][111];
 
int N;
 
bool exists(int x,int y){
    if(x>=0 && x<N && y>=0 && y<=N)
        return true;
    return false;
}
 
int make_grid(){
    scanf("%d",&N);
    if(N==0) return 0;
    for(int i=N-1;i>=0;i--)
        for(int j=0;j<N;j++)
            scanf("%d%d%d%d",&allowed[i][j].n,&allowed[i][j].s,&allowed[i][j].w,&allowed[i][j].e);
}
 
int bfs(int sx,int sy,int tx,int ty){
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) ans[i][j]=-1;
    queue<ii> q;
    int x,y;
    q.push(ii(sx,sy));
    ans[sx][sy]=0;
    while(!q.empty()){
        ii top= q.front(); q.pop();
        x=top.first; y=top.second;
        if(exists(x+1,y) && allowed[x][y].n==1){
            if(ans[x+1][y]> ans[x][y]+1 || ans[x+1][y]==-1)
                ans[x+1][y]=ans[x][y]+1,q.push(ii(x+1,y));
        }
        if(exists(x-1,y) && allowed[x][y].s==1){
            if(ans[x-1][y]> ans[x][y]+1 || ans[x-1][y]==-1)
                ans[x-1][y]=ans[x][y]+1,q.push(ii(x-1,y));
        }
        if(exists(x,y+1) && allowed[x][y].e==1){
            if(ans[x][y+1] > ans[x][y]+1 || ans[x][y+1]==-1)
                ans[x][y+1]=ans[x][y]+1,q.push(ii(x,y+1));
        }
        if(exists(x,y-1) && allowed[x][y].w==1){
            if(ans[x][y-1] > ans[x][y]+1 || ans[x][y-1]==-1)
                ans[x][y-1]=ans[x][y]+1,q.push(ii(x,y-1));
        }
 
    }
    return ans[tx][ty];
 
}
 
int main(){
    int Q,bx,by,tx,ty;
    while(make_grid()){
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d%d%d%d",&bx,&by,&tx,&ty);
            int res=bfs(by,bx,ty,tx);
            if(res==-1)
                printf("Impossible\n");
            else
                printf("%d\n",res);
        }
    }
    return 0;
}
 