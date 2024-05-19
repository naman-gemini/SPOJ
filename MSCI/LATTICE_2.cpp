#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
    FILE *f;
    for(double n=0;n<5000;n++)
    {
        f=fopen("C:\\E Drive\\Lattice.txt","a+");
        double sum=0;
        double x,y;

        for(x=1;x<=n;x++)
        {
            sum+=4*(n-x+1)*(n+1)*x;
            for(y=1;y<x;y++)
            {
                sum+=8*(n-x+1)*(n-y+1)*sqrt(x*x+y*y);
            }
            sum+=4*(n-x+1)*(n-y+1)*sqrt(x*x+y*y);
        }
        printf("%.2lf\n",sum/pow(n+1,4));
        fprintf(f,"%.2lf\n",sum/pow(n+1,4));
    }
    fclose(f);
    return 0;
}
