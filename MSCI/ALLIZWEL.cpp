#include<cstdio>
#include<cstdlib>
#include<cctype>
//#define PRINT
using namespace std;

char a[105][105];
bool visited[105][105];

int main()
{
    int t,row,col;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&row,&col);
        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            do
            scanf("%c",&c);
            while (isspace(c));
            a[i][j]=c;
        }

        #ifdef PRINT
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
        #endif

        for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        if(a[i][j]=='A')

    }
}
