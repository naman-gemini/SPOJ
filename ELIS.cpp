#include<cstdio>
#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;

int LS[25];

int solve(int *arr,int n)
{
	LS[0]=1;
	for(int i=1;i<n;i++)
	{
		LS[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && LS[i]<=LS[j]) 
				LS[i]=LS[j]+1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(LS[i]>ans) ans=LS[i];
	}
	return ans;
}

int main()
{
	int t;
	int arr[25];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("%d\n",solve(arr,t));
	return 0;
}