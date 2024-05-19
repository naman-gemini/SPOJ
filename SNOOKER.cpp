#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
	if (b==0)
	return a;

	else
	return gcd(b,a%b);
}
int main()
{
	int M,N,t;
	while(1)
	{
		scanf("%d %d",&M,&N); if (M==0&&N==0) break;
		t=gcd(M,N);
		M/=t;
		N/=t;
		printf("%d\n",(M+N-2)*4);
	}
	return 0;
}
