#include<stdio.h>
#include<math.h>

#define range1 1
#define range2 20
#define range3 300
#define range4 4000
#define range5 50000
#define range6 600000
#define range7 7000000
#define range8 80000000

int val_x(int digits)
{
    int x;
    switch (digits)
    {
       case 1:
       x=0;
       break;

       case 2:
       x=range1;
       break;

       case 3:
       x=range2;
       break;

       case 4:
       x=range3;
       break;

       case 5:
       x=range4;
       break;

       case 6:
       x=range5;
       break;

       case 7:
       x=range6;
       break;

       case 8:
       x=range7;
       break;

       case 9:
       x=range8;
    }

    return x;

}

long long int sum_digits(int a)
{
    int n,sum=0;
    do
    {
        n=a%10;
        sum+=n;
        a=a/10;
    }
    while(a!=0);
    return sum;
}

int digit_len(int num)
{
    int count=1;
    while((num/10)!=0)
    {
        count++;
        num/=10;
    }
    return count;
}

int main()
{
    int a,b,i,curr_val=0;
    long long int suma,sumb;
    while(1)
    {
        suma=0;sumb=0;
        scanf("%d",&a);
        scanf("%d",&b);

        if(a==-1 && b==-1) return 1;

        else if (a==0 && b==0) printf("0\n");

        else if (a==b) printf("%d\n",sum_digits(b));

        else
        {
            int n[9]={0,0,0,0,0,0,0,0,0};
            int num=a,i,k;
            int x;
            int proper_num=num;
            int digits=digit_len(num);                      //correct till here (checked)
            x=val_x(digits);


            for(k=0;k<9;k++)
            {
                n[k]+=x;                        //part 1
            }

            int difference;
            int naman;
            difference=0;

            if(digits==1)
            {
                num=0;
                goto digits_1;
            }


            while(digit_len(num)>1)
            {
                naman=num/((int)(pow(10,digits-1)));
                printf("naman=%d\n",naman);
                digits=digit_len(num);
                x=val_x(digits);
                printf("x=%d\n",x);
                for(i=1;i<naman;i++)
                {
                    for(k=0;k<9;k++)
                    {
                        n[k]+=x;
                    }

                    n[i-1]+=((int)(pow(10,digits-1)));
                }

                suma+=difference*sum_digits((proper_num/(int)(pow(10,digits-1))));
                difference=(num/(int)(pow(10,digits-1)))*(int)(pow(10,digits-1));
                curr_val+=(num/pow(10,digits-1))*(pow(10,digits-1));
                printf("curr_val=%d\n",curr_val);
                num=num%(int)(pow(10,digits-1));
            }
            curr_val=(proper_num/10)*10;
            printf("curr_val=%d\n",curr_val);
            printf("suma=%lld\n",suma);
            suma+=((sum_digits(proper_num/10))*(a-curr_val+1));
            printf("suma=%lld\n",suma);

            digits_1:
            suma+=(((a-curr_val)*(a-curr_val+1))/2);
            printf("suma=%d\n",suma);

            printf("%d\n",n[0]);
            printf("%d\n",n[1]);
            printf("%d\n",n[2]);
            printf("%d\n",n[3]);
            printf("%d\n",n[4]);
            printf("%d\n",n[5]);
            printf("%d\n",n[6]);
            printf("%d\n",n[7]);
            printf("%d\n",n[8]);

            suma+=1*n[0]+2*n[1]+3*n[2]+4*n[3]+5*n[4]+6*n[5]+7*n[6]+8*n[7]+9*n[8];
            printf("%lld\n",suma);

        }

    }

}
