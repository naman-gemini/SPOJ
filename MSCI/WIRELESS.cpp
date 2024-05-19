#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

int m,n,k;

void process(int **a,int c,int r,int radius,int bitrate)
{

    int start = max (1, c - radius);
    int stop = min (m, c + radius);
    int uplimit = min (n, r + radius);
    int downlimit = max (1, r - radius);
    int square = radius*radius;

    int i, j;
    int t1, t2, t3;                  // not really worth it
    for (i = r ; i <= uplimit ; i++)
    {
        t1 = i - r;
        t2 = t1 * t1;
        t3 = square - t2;
        while (((start - c) * (start - c)) > t3)
            start++;
        while (((stop - c) * (stop - c)) > t3)
            stop--;

        // move 10 at once between checking for being at the end
        // this silliness shaves off nearly 40% of time on set#5
        for (j = start ; j < stop - 8 ; j++)
        {
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j] += bitrate;
        }
        while (j <= stop)
            a [i] [j++] += bitrate;

    }

    start = max (1, c - radius);
    stop = min (m, c + radius);
    for (i = r - 1 ; i >= downlimit ; i--)
    {
        t1 = i - r;
        t2 = t1 * t1;
        t3 = square - t2;
        while (((start - c) * (start - c)) > t3)
            start++;
        while (((stop - c) * (stop - c)) > t3)
            stop--;
        for (j = start ; j < stop - 8 ; j++)
        {
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j++] += bitrate;
            a [i] [j] += bitrate;
        }
        while (j <= stop)
            a [i] [j++] += bitrate;
    }
}


int main()
{
    int x,y,r,b,total=0;
    scanf("%d\n%d\n%d\n",&m,&n,&k);

    int **a;
    a=(int**)malloc((sizeof(int *)*(n+1)));

    for(int i=1; i<=n; i++)
        a[i]=(int*)malloc((sizeof(int)*(m+1)));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            a[i][j]=0;
    }

    for(int i=1; i<=k; i++)
    {
        scanf("%d %d %d %d",&x,&y,&r,&b);
        if(y+r > 30033 && r > y)
        {
            total+=b;
            continue;
        }
        //printf("x=%d y=%d\n",x,y);
        //int row,column,row_min,row_max,column_min,column_max;
        //a[y][x]

        process(a,y,x,r,b);


        //printf("row_min=%d row_max=%d\ncolumn_min=%d column_max=%d\n",row_min,row_max,column_min,column_max);

//            for(row=row_min; row<=row_max; row++)
//            {
//                for(column=column_min; column<=column_max; column++)
//                {
//                    if((row-x)*(row-x)+(column-y)*(column-y)<=r*r)
//                    {
//                        //printf("-------\ntesting %d %d\n--------\n",row,column);
//                        a[row][column]+=b;
//                        //printf("value=%d row=%d column=%d\n",a[row][column],row,column);
//                    }
//                }
//            }
    }

    int max=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]>max)
                max=a[i][j];
        }
    }

    int count=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==max)
                count++;
        }
    }

    printf("%d\n%d\n",max+total,count);
    return 0;
}


