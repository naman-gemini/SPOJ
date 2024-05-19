#include<cstdio>
#include<iostream>
#include<algorithm>
#define DEBUG(x) printf(#x"=%d\n",x)
#define MAX 25
using namespace std;

int c[MAX];

int solve(int *a,int n)
{
	int maxlen=0;
	c[0]=a[0];

	for(int i=1;i<n;i++)
	{
		if(a[i]>c[maxlen]) c[++maxlen]=a[i];
		else c[lower_bound(c,c+maxlen,a[i])-c]=a[i];
	}
	return maxlen+1;
}

int main()
{
	int t;
	int arr[MAX];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("%d\n",solve(arr,t));
	return 0;
}
