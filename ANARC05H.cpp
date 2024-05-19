#include<cstdio>
#include<cctype>
using namespace std;

int numbers,number[30];

int read_input()
{
    int c;
    while(isspace(c=getchar()));
    if(!isdigit(c)) return 0;
    numbers=0;
    do number[numbers++]=c-'0';
    while(isdigit(c=getchar()));
    return 1;
}

int count_ways(int pos,int min)
{
    int result=0,sum=0,i;
    if(pos==numbers) return 1;
    for(i=pos;i<numbers;i++)
    {
        sum+=number[i];
        if(sum>=min)
        result+=count_ways(i+1,sum);
    }
    return result;
}

int main()
{
    int caseno=0;

    while(read_input())
    {
        printf("%d. %d\n",++caseno,count_ways(0,0));
    }
    return 0;
}
