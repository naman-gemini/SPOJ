#include<cstdio>
#include<cstdlib>
#include<vector>
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;

vector<int> pos;
vector<vector<int> > mat;

/*
for row insertion mat.push_back(vector<int>());
for column insertion mat[i].push_back(value);
*/

void init_row(int n,int r)
{
    mat.push_back(vector<int>());
    for(int i=0;i<n;i++) mat[r].push_back(0);
}

void print_mat(int row)
{
    for(int i=0;i<mat[row].size();i++) printf("%d ",mat[row][i]);
}

int main()
{
    int t,n,min,max,val,row;
    scanf("%d",&t);
    while(t--)
    {
        min=10000000;
        max=-1;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            pos.push_back(val);
            if(val>max) max=val;
            if(val<min) min=val;
        }
        for(int i=0;i<pos.size();i++)
        pos[i]-=min;

        row=0;

        init_row(n,row);

        for(int i=0;i<pos.size();i++)
        {
            if(mat[row][pos[i]]==0) mat[row][pos[i]]=1;
            else if(mat[row][pos[i]]==1)
            {
                row++;
                init_row(n,row);
                mat[row][pos[i]]=1;
            }
        }

        for(int i=row;i>=0;i--)
        {
            print_mat(i);
            printf("\n");
        }

    }
}
