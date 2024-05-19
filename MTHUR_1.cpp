#include<cstdio>
#include<algorithm>

using namespace std;

int n1[10001];
int n2[10001];
int cum[10001];

int diff[10001];

//Basically make cases when upper bound-1 does exists, and where it does not exist


int main()
{

    int t,N,M,z,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%d",&n1[i]);
        }
        for(int i=0; i<N; i++)
        {
            scanf("%d",&n2[i]);
        }
        for(int i=0; i<N; i++) diff[i]=n1[i]-n2[i];
        sort(diff,diff+N);
        for(int i=0; i<N; i++) cum[i]=0;
        cum[0]=diff[0];
        for(int i=1; i<N; i++)cum[i]+=diff[i]+cum[i-1];
        int miN=1e+8;
        scanf("%d",&M);
        int val=0,curr;
        for(int i=0; i<M; i++)
        {
            scanf("%d",&z);
            int *lb;
            lb=lower_bound(diff,diff+N,z);
            if(lb-diff==0)
            {
                curr=cum[N-1]-(N)*z;
                if(curr< miN)
                    miN=curr,val=z;
                else if(curr==miN && z<val)
                    val=z;
                //printf("%d\n",curr);
            }
            else
            {
                curr=cum[N-1]-cum[(lb-diff)-1]-z*(N-(lb-diff))+ (lb-diff)*z-cum[lb-diff-1];
                if(curr < miN)
                    miN=curr,val=z;
                else if (curr==miN && z < val)
                    val=z;
                //printf("%d\n",curr);
            }
        }
        printf("%d\n",val);

    }

    return 0;
}
