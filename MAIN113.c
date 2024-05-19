#include<stdio.h>
#include<math.h>

void main()
{
      int T,N;
      scanf("%d",&T);
      while(T--)
      {
           scanf("%d",&N);
          if(N==1)
          {
                  printf("3\n");
          }
          
          else if (N==2)
          {
               printf("9\n");
          }
          
          else      
          printf("%lld\n",(long long int)(pow(3,N))-6*(N-2)* (long long int)(pow(3,(N-3)))+6*(N-3));
      }
      
}     
