#include<stdio.h>
char a[11][10]={"one","two","three","four","five","six","seven","eight","nine","ten"};
char b[11][11]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char t[9][11]={"twenty ","thirty ","fourty ","fifty ","sixty ","seventy ","eighty ","ninety "};
int ck(int z){if(z>=1000)return 1;else if(z>=100)return 2;else if(z>10)return 3;else return 0;}
void pr(int z,char *s){int n;if(z<=10) printf("%s %s",a[z-1],s);else if(z>10 && z<20) printf("%s %s",b[(z-10)-1],s);else if(z>=20){printf("%s",t[(z-20)/10]);n=z%10;printf("%s %s",a[n-1],s);}}
int main(){int z,n,ch=1;scanf("%d",&z);if(z==0)printf("zero");while( ch!=0){ch=ck(z);switch(ch){case 1:n=z/1000;pr(n,"thousand ");z=z-n*1000;break;
case 2:n=z/100;pr(n,"hundred ");z=z-n*100;break;case 3:if(z>10 && z<20){printf("%s ",b[(z-10)-1]);return 0;}else{printf("%s",t[(z-20)/10]);z=z%10;}break;}}printf("%s",a[z-1]);return 0;}
