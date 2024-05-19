#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
    FILE *f;
    for(int n=1;n<=5000;n++)
    {
        f=fopen("C:\\E Drive\\Lattice.txt","a");
        double sum=0,dist;
        double max=n*n*n*n;
        //(i,j) (p,q)
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int p=1;p<=n;p++)
                {
                    for(int q=1;q<=n;q++)
                    {
                        dist=(i-p)*(i-p)+(j-q)*(j-q);
                        dist=sqrt(dist);
                        sum+=dist/max;
                    }
                }
            }
        }
        printf("Case %d:%.2lf\n",n,sum);
        fprintf(f,"%.2lf\n",sum);
    }
    //fclose(f);

}
