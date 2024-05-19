#include<stdio.h>
#include<math.h>

int solution(int n)
{
    int counter_three=0;
    if(n%2==0) while(n%2==0) n=n/2;
    if(n%3==0) {while(n%3==0) {n=n/3; counter_three++;} if(counter_three %2 != 0) return 0;}
    int i,p=sqrt(n),product=1,counter_1,counter_3;
    for(i=5;i<=n;i+=6)
    {
        counter_1=0;
        counter_3=0;
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
                if(i%4==1)
                counter_1++;
                if(i%4==3)
                counter_3++;
            }
            if (counter_3 % 2 != 0) return 0;
        }
        product*=counter_1+1;
    }
    //printf("n=%d\n",n);
    for(i=7;i<=n;i+=6)
    {
       // printf("i=%d\n",i);
        counter_1=0;
        counter_3=0;
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
                if(i%4==1)
                counter_1++;
                if(i%4==3)
                counter_3++;
            }
            //printf("counter_3=%d\n",counter_3);
            if (counter_3 % 2 != 0) return 0;
        }
        product*=counter_1+1;
    }

    if(product%2==0) return product/2;
    else return (product+1)/2;

}
int main()
{
    int i,n;
    for(i=0;i<50;i++)
    {
        scanf("%d",&n);
        printf("%d\n",solution(n));
    }
    return 0;
}
