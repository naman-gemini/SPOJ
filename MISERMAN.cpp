#include<cstdio>

int b[101][101];

int main()
{
    int n,m;

    while(scanf("%d %d",&n,&m) == 2)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&b[i][j]);

        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<m; j++)
            {
                if(j==0)
                    b[i][j] += (b[i+1][j+1] > b[i+1][j]?b[i+1][j]:b[i+1][j+1]);
                else if(j==m-1)
                    b[i][j] += (b[i+1][j] > b[i+1][j-1])?b[i+1][j-1]:b[i+1][j];

                else
                {
                    if (b[i+1][j-1] <= b[i+1][j] && b[i+1][j-1] <= b[i+1][j+1])
                        b[i][j] += b[i+1][j-1];
                    else if (b[i+1][j] <= b[i+1][j-1] && b[i+1][j] <= b[i+1][j+1])
                        b[i][j] += b[i+1][j];
                    else
                        b[i][j] += b[i+1][j+1];

                }
            }
        }

        int min = b[0][0];
        for(int i=1; i<m; i++)
        {
            if(b[0][i] < min) min = b[0][i];
        }

        printf("%d\n",min);

    }


    return 0;
}

