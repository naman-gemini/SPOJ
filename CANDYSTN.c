#include<stdio.h>
#include<math.h>
int main()
{
	int max_bag;
	int bag;
	int coll;
	int max_coll;
	int T,N,M;
	int milestone[10010];
	int i,j,k;
	int add;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		bag=0;
		max_bag=0;
		coll=0;
		max_coll=0;
		scanf("%d%d",&N,&M);
		for(j=0;j<M;j++)
		{
			scanf("%d",&milestone[j]);
		}
		for(j=1;j<M;j++)
		{
			add=milestone[j]-milestone[j-1];
			if(add>0)
			{
				coll=coll+add;
				bag=bag-add;
				if(bag<0)
				{
					if(max_bag>bag)
						max_bag=bag;
				}
			}
			if(add<0)
			{
				coll=coll+add;
				bag=bag-add;
				if(coll<=0)
				{
					if(max_coll>coll)
						max_coll=coll;
				}
			}
			if(add==0)
			{
				coll=coll-1;
				if(coll<=0)
				{
					if(max_coll>coll)
						max_coll=coll;
				}
			}

		}
		max_bag=max_bag*(-1);
		max_coll=max_coll*(-1);
		max_coll=max_coll+1;
		if(N-max_bag<0)
		{
			printf("-1\n");
			continue;
		}
		if(N-max_bag-max_coll<0)
		{
			printf("-1\n");
			continue;
		}
			printf("%d\n",max_coll);
	}


	return 0;
}
