#include<cstdio>
#include<algorithm>

using namespace std;


int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap(int x)
{
    return ((x % 4 ==0 && x % 100 != 0) || ( x % 400 == 0)) ;
}


int main()
{
    int n,d,m,y,c;
    int nd,nm,ny,nc;
    int count;
    int sum;


    while(scanf("%d",&n) && n)
    {
        count = sum = 0;

        nm = nd = ny = nc = -1;

        for(int i=0; i<n; i++)
        {

            scanf("%d %d %d %d",&d,&m,&y,&c);

            if(d==nd && m == nm && y ==ny)
            {
                count++;
                sum += c - nc;
            }

            nd = d+1;
            nm = m;
            ny = y;
            nc =c;

            if(nd > days[m] + (m == 2 && isleap(y)))
            {

                nd = 1;
                if(++nm > 12) nm =1, ++ny;
            }

        }

        printf("%d %d\n",count,sum);
    }
    return 0;
}
