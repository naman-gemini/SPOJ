#include<stdio.h>
#include<math.h>

int main()
{
    int R,B;
    int num1,num2;
    scanf("%d %d",&R,&B);
    num1=((R+4)+(int)(sqrt(pow(4+R,2)-16*(R+B))))/4;
    num2=((R+4)-(int)(sqrt(pow(4+R,2)-16*(R+B))))/4;
    printf("%d %d",num1,num2);
    return 0;
}
