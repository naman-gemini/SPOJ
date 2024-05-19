#include<cstdio>
#include<cstring>
#define MAX 71
using namespace std;

int a[MAX][MAX];
int arr[MAX];

void chk_slide(int row,int col)
{
    if(row==0) a[row][col]=1; //at ground
    else if(a[row-1][col-1]==1 && a[row-1][col+1]==1) a[row][col]=1; //no sliding
    else if(a[row-1][col+1]==0) chk_slide(row-1,col+1); //recursive slide towards right
    else if(a[row-1][col-1]==0) chk_slide(row-1,col-1); //recursive slide towards left
}

int main()
{
    int t,n,min,x,row;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(arr,0,sizeof(arr));
        min=1000000000;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]<min) min=arr[i];
        }
        for(int i=0; i<n; i++) arr[i]-=min;

        row=0;
        for(int i=0; i<n; i++)
        {
        //giving offset of MAX/2
            x=arr[i]+MAX/2;
            if(a[row][x]==0) chk_slide(row,x);
            else if(a[row][x]==1)
            {
                row++;
                chk_slide(row,x);
            }
        }
        int start,end,top;

        //removing starting and trailing zeroes
        for(int i=0; i<MAX; i++)
        {
            if(a[0][i]==1)
            {
                start=i;
                break;
            }
        }

        for(int i=MAX-1; i>=0; i--)
        {
            if(a[0][i]==1)
            {
                end=i;
                break;
            }
        }
        bool flag=true;

        //finding upper bound
        for(int i=MAX-1; i>=0; i--)
        {
            if(!flag) break;
            for(int j=start; j<=end; j++)
            {

                if(a[i][j]==1)
                {
                    top=i;
                    flag=false;
                    break;
                }

            }
        }

        //printing the mat

        for(int i=top; i>=0; i--)
        {
            for(int j=start; j<=end; j++)
                if(a[i][j]==1) putchar('O');
                else putchar('-');
            printf("\n");
        }
    }
    return 0;
}
