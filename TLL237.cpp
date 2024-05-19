#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int find_min(int *a,int n)
{
    int min_val=a[0];
    int min_index=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]<min_val)
        {
            min_val=a[i];
            min_index=i;
        }
    }
    return min_index;
}

int find_min_2(int *a,int n)
{
    int x=find_min(a,n);
    int val=a[x];
    int min=1000000;
    int min_index=0;
    for(int i=0 ; i<n ; i++)
    {
        if(i!=x)
        {
            if(a[i]==val) return i;
            if(a[i]<min)
            {
                min=a[i];
                min_index=i;
            }
        }
    }
    return min_index;
}

int main()
{
    int n;
    char s[100005];
    char c;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int j=0; j<=n; j++) a[j]=0;
    scanf("%s",s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='1')
        {
            a[find_min(a,n)]++;
        }
        else if(s[i]=='2')
        {
            a[find_min_2(a,n)]++;
        }

    }
    printf("%d %d\n",a[find_min(a,n)],a[find_min_2(a,n)]);
    return 0;
}
