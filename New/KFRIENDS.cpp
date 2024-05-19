#include<cstdio>
#include<vector>
using namespace std;
vector<pair<int,int> > coords;
bool pos[128][128];
int n;

bool exists(int x,int y){
    if(x>=1 && x<=100 && y>=1 && y<=100)
        if(pos[x][y]) return true;
    return false;
}

int check_coords(pair<int,int> cord){
    int x=cord.first,y=cord.second;
    int in_degree=0;
        if(exists(x+2,y+1))in_degree++;
        if(exists(x+2,y-1))in_degree++;
        if(exists(x-2,y+1))in_degree++;
        if(exists(x-2,y-1)) in_degree++;
        if(exists(x+1,y+2))in_degree++;
        if(exists(x+1,y-2))in_degree++;
        if(exists(x-1,y+2))in_degree++;
        if(exists(x-1,y-2))in_degree++;

    return in_degree;
}


int main(){
    int t,x,y,max_colors;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) pos[i][j]=false;
        max_colors=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            pos[x][y]=true;
            coords.push_back(make_pair(x,y));
        }
        for(int i=0;i<coords.size();i++){
            int curr=check_coords(coords[i]);
            if(curr> max_colors) max_colors=curr;
        }
        printf("%d\n",max_colors);
        coords.clear();
    }
    return 0;
}

