#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int N,M,*a;
    while(scanf("%d %d",&N,&M) == 2)
    {
        a = (int*) malloc (N*sizeof(int));
        memset(a,0,sizeof a);
        int L =0;
        int max = 0;
        long long int sum  =0;
        for(int i=0; i<N; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];

            while(sum > M)
            {
                sum -= a[L++];


            }
            if(sum > max) max= sum;
        }

        printf("%d\n",max);

    }
    return 0;
}
