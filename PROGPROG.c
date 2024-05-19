#include <stdio.h>
 
int F[1000001];
const int MOD = 100000007;
 
void preprocess()
{
     int i,c;
	for(i = 1; i <= 1000000; i++)
		F[i] = 1;
		
	for(c = 2; c <= 500000; c++)
		for(i = c; i+c <= 1000000; i += c)
		{	
			F[i+c] += F[i];
			if(F[i+c] >= MOD)
				F[i+c] -= MOD;
		}
}
 
int main()
{
	preprocess();
	int T;
	scanf("%d", &T);
	int N;
	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n", F[N]);	
	}
	return 0;
}

