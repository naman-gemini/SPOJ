#include<cstdio>
#include<cstdlib>

int main()
{
    int n;

    scanf("%d",&n);
    int *arr;
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    scanf("%d",&arr[i]);

    int last = n;

    for(int i=n-1; i>=0; i--)
    if(arr[i]==last)
    last--;

    printf("%d\n",last);

    return 0;
}
