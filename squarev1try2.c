#include<stdio.h>#include<math.h>
int main(){int counter;long long int i,j,n,x,p;for(x=0; x<50; x++){counter=0;scanf("%lld",&n);p=(long long)(sqrt(n/2));for(i=0; i<=p; i++)for(j=p; j<=n; j++){if(n==(i*i+j*j)){counter++;}}printf("%d\n",counter);}return 0;}
