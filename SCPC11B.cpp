#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define run 1422

using namespace std;

int main()
{
    int t,i;
    bool flag;
    int *pos;
    while(scanf("%d",&t))
    {
        if(t==0) break;
        flag = true;
        pos = (int*)malloc(t*sizeof(int));

        for(i=0; i<t; i++)
        {
            scanf("%d",&pos[i]);
        }

        sort(pos,pos+t);
        i=0;
        while(i<t-1)
        {
            if(pos[i+1] - pos[i] > 200)
            {
                flag = false;
                break;
            }
            i++;
        }

        if((2 * (1422 - pos[t-1])) > 200 || pos[0] > 200)
        {
            flag = false;
        }


        if(flag) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");

    }
    return 0;
}
