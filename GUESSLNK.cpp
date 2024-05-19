#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    char input[60];
    int i,j;
    int num[15];
    while(scanf("%s",input))
    {
        for(j=0,i=36;i<50;i++,j++)
        {
            num[j]=input[i];
        }
    }
}
