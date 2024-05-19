#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int **diff;
    int cols,rows,col,row,radius,bitrate,left,right;
    int total=0;

    scanf("%d %d",&rows,&cols);
    diff=(int**)malloc(sizeof(int*)*(rows+1));
    for(int i=0; i<=rows; i++)
    {
        diff[i]=(int*)malloc(sizeof(int)*(cols+1));
    }

    for(int i=0; i<=rows; i++)
    {
        for(int j=0; j<=cols; j++)
        {
            diff[i][j]=0;
        }
    }

    int k;
    scanf("%d",&k);

    for(int i=0; i<k; i++)
    {
        scanf("%d %d %d %d",&col,&row,&radius,&bitrate);
        row--;
        col--;

        for(int j=max(0,col-radius); j<=min(cols-1,col+radius); j++)
        {
            left=max(0,row-(int)sqrt(radius*radius-(col-j)*(col-j)));
            right=min(rows-1,row+(int)sqrt(radius*radius-(col-j)*(col-j)));

            diff[left][j]+=bitrate;
            diff[right+1][j]-=bitrate;
        }
    }

    int best=0;
    int count=0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(i>0)
                diff[i][j]+=diff[i-1][j];
            if(diff[i][j]==best)
                count++;
            if(diff[i][j]>best)
            {
                best=diff[i][j];
                count=1;
            }
        }
    }
    printf("%d\n%d\n",best+total,count);
    for(int i=0; i<=rows; i++)
    {
        free(diff[i]);
    }
    return 0;
}
