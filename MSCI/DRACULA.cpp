#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long int array[200];

int sum(long long a)
{
	int sum=0;
	while(a)
	{
		sum+=a%10;
		a/=10;
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int ticket=0;
		long long int a,b,x,i;
		scanf("%lld %lld %lld",&a,&b,&x);
		//printf("a=%lld b=%lld x=%lld\n",a,b,x);
		for(i=a;i<=b;i++)
		{
			array[sum(i)]++;
		}
		//printf("%lld",*v.begin());
		//printf("\n%lld\n",*(v.end()-1));

		for(int i=0;i<200;i++)
		{
		    if(x<i) break;
		    while(array[i])
		    {
		        array[i]--;
		        ticket++;
		        x-=i;
            }
		}
		printf("%lld\n",ticket);

		for(int i=0;i<200;i++)
		{
		    array[i]=0;
		}
		//printf("%d\n",sum(a));
	}
	return 0;
}

