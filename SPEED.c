#include<stdio.h>
#include<math.h>

int GCD(int a, int b)
{
    if(b==0)
    return a;
    return GCD (b, a%b);
}

int main()
{
    int T,a,b,i;
    scanf("%d",&T);
    while(T--)
    {
              scanf("%d",&a);
              scanf("%d",&b);
              i=GCD(abs(a),abs(b));
              a/=i;
              b/=i;
              printf("%d\n",abs(a-b));
    }
    
    return 0;
}
