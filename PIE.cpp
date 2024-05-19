#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
const double PI= acos(-1.0);
int main()
{
	int te;
	scanf("%d",&te);
	while(te--)
	{
		int n,c;
		scanf("%d%d",&n,&c);c+=1;
		vector<int>v(n);
		vector<double>v1(n);
		fo(i,n)
		{
			scanf("%d",&v[i]);
			v1[i]=PI*v[i]*v[i];
		}
		double lo=0.0,hi=accumulate(v1.begin(),v1.end(),0.0),mid;
		while(hi-lo>1e-9)
		{
			int cnt=0;
			mid=(lo+hi)/2;
			fo(i,n)
			{
				if(v1[i]/mid>=1.0)
					cnt+=(int)(v1[i]/mid);
			}
			if(cnt>=c)lo=mid;
			else hi=mid;
		}
		printf("%.4f\n",lo);
	}
	return 0;
}
