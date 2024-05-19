#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r;
		scanf("%d",&r);
		printf("%.4lf\n",8*pow(r,3)*(2-sqrt(2)));
	}
	return 0;
}