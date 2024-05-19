#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t;                          //test cases
    int frame;                      //current frame
    int d1;                         //delivery 1
    int d2;                         //delivery 2
    int d3;                         //delivery 3 (for 10th frame only)
    int score;                      //final score
    int sum;                        //value of d1+d2 for last frame
    bool strike;                    //there was a strike previously (at d1)
    bool spare;                     //there was a spare previously
    scanf("%d",&t);
    while(t--)
    {
        frame=1,score=0;
        strike=false,spare=false;
        while(frame<10)
        {
            scanf("%d",&d1);
            if(strike || spare) score+=2*d1;
            else score+=d1;

            if(d1!=10)
            {
                scanf("%d",&d2);
                if(strike) score+=2*d2;
                else score+=d2;
                strike=false;
            }
            else
            {
                d2=0;
                strike=true;
            }
            sum=d1+d2;
            if(sum==10 && strike==false) spare=true;
            else spare=false;
            frame++;
            printf("current score=%d\n",score);
        }
        sum=0;
        scanf("%d %d",&d1,&d2);
        sum+=d1+d2;
        if(d1==10 || d1+d2==10)
        {
            scanf("%d",&d3);
            sum+=d3;
        }
        if(strike) score+=2*sum;
        else if(spare) score+=sum+d1;
        else score+=sum;

        printf("Final score=%d\n",score);
    }
}
