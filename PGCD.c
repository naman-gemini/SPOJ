#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int *moebiussum;
bool *iscomposite;
int *primes;
int *summoebiussum;
int numprimes;
int at[100],bt[100];
int t;
int a,b;
int MAXX2;
int min(int x,int y)
{
  if(x<y)
    return x;
  else
    return y;
}

void go(int number,int previd,int numps,bool sqfr)
{
  int i;

  if(sqfr)
    {

      moebiussum[number]=numps*(((numps%2)<<1)-1);
      if(primes[previd]<=MAXX2/number)
	go(number*primes[previd],previd,numps,0);

    }
  else
    moebiussum[number]=1-((numps%2)<<1);


  for(i=previd+1;primes[i]<=MAXX2/number;i++)
    {
      go(number*primes[i],i,numps+1,sqfr);
    }


  return ;
}




int main()
{
   int x,tc,i,sq,inc,uplimit,finalx,j;
  int maxmoeb;
  long long int count;

  MAXX2=-1;
  scanf("%d",&t);
  for(tc=1;tc<=t;tc++)
    {
      scanf("%d %d",&a,&b);
      at[tc]=a;bt[tc]=b;
      if(MAXX2<min(at[tc],bt[tc]))
	MAXX2=min(at[tc],bt[tc]);

    }
  MAXX2+=10000;

 moebiussum=(int *)malloc(sizeof(int)*(MAXX2+100000));
 iscomposite=(bool *)malloc(sizeof(bool)*(MAXX2+100000));
 primes=(int *)malloc(sizeof(int)*(MAXX2+100000));
 summoebiussum=(int *)malloc(sizeof(int)*(MAXX2+100000));
 memset(moebiussum,0,sizeof(moebiussum));
 memset(iscomposite,0,sizeof(iscomposite));


  for(i=2;i*i<=MAXX2;i++)
    if(!iscomposite[i])
      {
	sq=i*i;
        inc;
	if(i==2)
	  inc=2;
	else
	  inc=i*2;
	for(j=sq;j<=MAXX2+100;j+=inc)
	  iscomposite[j]=1;
      }

  numprimes=3;primes[0]=2;primes[1]=3;primes[2]=5;

  for(i=7;i<=MAXX2+1000;i+=2)
      if(!iscomposite[i])
	{
       	  primes[numprimes]=i;
	  numprimes++;
	}

  for(i=0;primes[i]<=MAXX2;i++)
    go(primes[i],i,1,1);
  summoebiussum[0]=0;
  maxmoeb=-100000;
  for(i=1;i<=MAXX2;i++)
    {
    summoebiussum[i]=summoebiussum[i-1]+moebiussum[i];
    if(summoebiussum[i]<maxmoeb)
      {
	printf("%d\n",summoebiussum[i]);
	maxmoeb=summoebiussum[i];
      }
    }
  for(tc=1;tc<=t;tc++)
    {
      a=at[tc];
      b=bt[tc];
      count=0;

      uplimit=min(a,b);

      finalx=-1;
      for(x=2;x<=uplimit;x++)
	{
	  if(a/x==1 && b/x==1)
	    {
	      finalx=x;
	      break;
	    }


	  count=count+(a/x)*((long long)(b/x)*moebiussum[x]);



	}
      if(finalx!=-1)
	count+=summoebiussum[uplimit]-summoebiussum[finalx-1];

      printf("%lld\n",count);



    }
  return 0;


}
