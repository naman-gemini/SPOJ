#include<stdio.h>
#include<math.h>
#include<conio.h>

int isPrime(int num)
{
    int i;
    if(num==2) return 1;
    if(num%2==0) return 0;
    for(i=3;i<=(int)(sqrt(num));i+=2)
        if(num%i==0)
            return 0;             //not a prime
        return 1;                 //is a prime

}

void prime_100000()
{
     int a,primes[10000],i;
     for(a=2,i=0;a<100000;a++)
     {
        if(isPrime(a))
        {
            primes[i]=a;
            i++;
        }
     }
}

int digit_len (int num)
{
    int count=1;
    while((num/10)!=0)
    {
        count++;
        num/=10;
    }
    return count;
}

int get_digits (int num)
{
    int i,digits[digit_len(num)];
    for(i=0;i<digit_len(num);i++)
    {
        digits[i]=num%10;             //digits[0] has one's digit, digits[1] has ten's and so on........
        num/=10;
    }

    for(i=0;i<digit_len(num);i++)
    {
        if(digits[i]==2 || digits[i]==3 || digits[i]==5 || digits[i]==7)
        return 0;
        // else if (digits[i]==1)
    }

}


int main()
{
    prime_100000();
    int i,non_primes[100000];
    non_primes[0]=1;
    for(i=2;i<=100000;i++)
    {

    }
    getch();
    return 0;
}
