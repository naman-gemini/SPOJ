#include <stdio.h>
#define MAX 500

char temp[2][MAX];
int a[MAX];


int main()
{
	int t,n,k,i,s,m1,m2,p,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		for(i=0;i<n;i++)
			temp[0][i]=temp[1][i]=0;

		s=1;
		temp[0][0]=1;
		p=1;
		while(k)
		{
			if (k&1)
			{
				for(i=0;i<n;i++)
					if (temp[1-s][i])
					{
						temp[s][(i+p)%n]^=1;
						m1=(i-p)%n;
						if (m1<0)
							m1+=n;
						temp[s][m1]^=1;
						temp[s][i]^=1;
						temp[1-s][i]=0;
					}
				s=1-s;
			}
			k>>=1;
			p<<=1;
		}
		for(i=0;i<n;i++)
		{
			m1=0;
			for(j=0;j+i<n;j++)
				if (temp[1-s][j])
					m1^=a[i+j];
			for(;j<n;j++)
				if (temp[1-s][j])
					m1^=a[i+j-n];
			printf("%d ",m1);
		}
		printf("\n");
	}
	return 0;
}
