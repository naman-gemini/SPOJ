#include<stdio.h>
#include<iostream>
#include<vector>
#define DEBUG if(0)

using namespace std;
char M[111][111];
bool used[111][111];
typedef pair<int,int> ii;

//Backtrack search. Keep track of positions of A's.
int R,C;

bool exists(int x,int y){

    if(x>=0 && x<R && y>=0 && y<C) return true;
    return false;

}

char pattern[]="ALLIZZWELL";

bool find(int x,int y, char a,int len){

    DEBUG cout << "visiting " << x << ' ' << y << endl;
    if(len==9)
        return true;

    if(exists(x+1,y)) if(!used[x+1][y]){

       if(M[x+1][y]==pattern[len+1]){
         used[x+1][y]=true;
         if(find(x+1,y,pattern[len+1],len+1))
            return true;
         used[x+1][y]=false;
       }
    }
     if(exists(x-1,y)) if(!used[x-1][y]){
       if(M[x-1][y]==pattern[len+1]){
         used[x-1][y]=true;
         if(find(x-1,y,pattern[len+1],len+1))
            return true;
         used[x-1][y]=false;
       }
    }
     if(exists(x+1,y+1)) if(!used[x+1][y+1]){
       if(M[x+1][y+1]==pattern[len+1] ){
         used[x+1][y+1]=true;
         if(find(x+1,y+1,pattern[len+1],len+1))
            return true;
         used[x+1][y+1]=false;
       }
    }
     if(exists(x+1,y-1)) if(!used[x+1][y-1]){
       if(M[x+1][y-1]==pattern[len+1]){
         used[x+1][y-1]=true;
         if(find(x+1,y-1,pattern[len+1],len+1))
            return true;
         used[x+1][y-1]=false;
       }
    }
     if(exists(x,y+1)) if(!used[x][y+1]){
       if(M[x][y+1]==pattern[len+1] ){
         used[x][y+1]=true;
         if(find(x,y+1,pattern[len+1],len+1))
            return true;
         used[x][y+1]=false;
       }
    }
     if(exists(x,y-1)) if(!used[x][y-1]){
       if(M[x][y-1]==pattern[len+1]){
         used[x][y-1]=true;
         if(find(x,y-1,pattern[len+1],len+1))
            return true;
         used[x][y-1]=false;
       }
    }
     if(exists(x-1,y-1)) if(!used[x-1][y-1]){
       if(M[x-1][y-1]==pattern[len+1] ){
         used[x-1][y-1]=true;
         if(find(x-1,y-1,pattern[len+1],len+1))
            return true;
         used[x-1][y-1]=false;
       }
    }
     if(exists(x-1,y+1)) if(!used[x-1][y+1]){
       if(M[x-1][y+1]==pattern[len+1] ){
         used[x-1][y+1]=true;
         if(find(x-1,y+1,pattern[len+1],len+1))
            return true;
         used[x-1][y+1]=false;
       }
    }

    return false;

}



int main(){

    int t,i,j;
    bool found;
    vector<ii> starts;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&R,&C);
        for(i=0;i<R;i++) scanf("%s",M[i]);
        for(i=0;i<R;i++) for(j=0;j<C;j++) {used[i][j]=false; if(M[i][j]=='A') starts.push_back(ii(i,j));}

        found=false;
        for(i=0;i<starts.size();i++){
           if(find(starts[i].first,starts[i].second,'A',0))
                {
                    found=true;
                    break;
                }
        }
        if(found)
            printf("YES\n");
        else
            printf("NO\n");
        starts.clear();
    }
    return 0;
}
