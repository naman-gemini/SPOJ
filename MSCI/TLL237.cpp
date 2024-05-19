#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

int main()
{
    int n,temp,temp2;
    char c;
    scanf("%d\n",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++) a[i]=0;
    priority_queue< int, vector<int>, greater<int> > pq (a,a+n);
    free(a);
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='1')
        {
            temp=pq.top();
            pq.pop();
            pq.push(++temp);
        }
        if(c=='2')
        {
            temp2=pq.top();
            pq.pop();
            temp=pq.top();
            pq.pop();
            pq.push(++temp);
            pq.push(temp2);
        }
    }
    temp=pq.top();
    pq.pop();
    temp2=pq.top();
    printf("%d %d\n",temp,temp2);
    return 0;
}
