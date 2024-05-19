#include<cstdio>

#include<cstdlib>
#include<queue>
using namespace std;

priority_queue< int, vector<int>, greater<int> > pq;

int main()
{
    int t,n;
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        flag=true;
        scanf("%d",&n);
        if(n==1)
        {
            scanf("%d",&n);
            printf("-1\n");
            continue;
        }

        int *a=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);

        for(int i=0;i<n-1;i++)
        if(a[i+1]>a[i]) flag=false;

        if(flag==true)
        {
            printf("-1\n");
            continue;
        }

        //find first big element
        //a[i-1] is small , a[i] is big
        int counter;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i-1]<a[i])
            {
                counter=i;
                break;
            }
        }

        int min=1000000;

        for(int i=counter;i<n;i++)
        {
            if(a[i]<min && a[i]>a[counter-1])
            min=a[i];
        }
        bool flag2=false;

        for(int i=counter;i<n;i++)
        {
            if(a[i]!=min || flag2)
            {
                pq.push(a[i]);
            }
            if(a[i]==min)
            {
                flag2=true;
            }
        }

        pq.push(a[counter-1]);
        a[counter-1]=min;

        for(int i=0;i<counter;i++)
        {
            printf("%d",a[i]);
        }

        while(!pq.empty())
        {
            printf("%d",pq.top());
            pq.pop();
        }

        printf("\n");

        free(a);


    }
    return 0;
}
