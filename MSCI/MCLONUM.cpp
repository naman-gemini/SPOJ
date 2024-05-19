#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char A[101],B[101];
    int i,j,n;
    char g[101],l[101];
    gets(A);
    gets(B);
    n=strlen(A);
    sort(B,B+n);
    for(i=0; i<n; i++)
        if(B[i]>=A[0])
            break;
    if( i < n )
    {
        g[0]=B[i];
        for(j=0; j<i; j++)
            g[j+1]=B[j];
        for(j=i+1; j<n; j++)
            g[j]=B[j];
        g[n]='\0';
        if(strcmp(g,A) >= 0)
        {
            printf("%s\n",g);
        }
        else
        {
            while( strcmp(g,A) < 0 )
            {
                if( next_permutation(g,g+n) == false)
                    break;
            }
            if( strcmp(g,A) >= 0)
                printf("%s\n",g);
            else
                printf("0\n");
        }
    }
    else
        printf("0\n");
    for(i=0; i<n; i++)
        if((B[i]<=A[0]) && (B[i]!='0') )
            break;
    if( i<n )
    {
        l[0]=B[i];
        for(j=n-1; j>i; j--)
            l[n-j]=B[j];
        for(j=i-1; j>=0; j--)
            l[n-j-1]=B[j];
        l[n]='\0';
        if(strcmp(l,A) < 0)
        {
            printf("%s\n",l);
        }
        else
        {
            while( strcmp(l,A) >= 0 )
            {
                if( prev_permutation(l,l+n) == false)
                    break;
            }
            if( (strcmp(l,A) < 0) && (l[0]!='0') )
                printf("%s\n",l);
            else
                printf("0\n");
        }
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
