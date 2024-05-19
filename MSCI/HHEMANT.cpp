#include<cstdio>
#include<iostream>
using namespace std;

int dummy[256],*charcode=dummy+128;

void init_charcodes()
{
    int i,c;
    for(i=-128; i<128; i++)
        charcode[i]=-1;
    charcode[' ']=0;
    for(i='A',c=1; i<'Z'; i++) charcode[i]=c++;
    for(i='a'; i<='z'; i++) charcode[i]=c++;
    for(i='0'; i<='9'; i++) charcode[i]=c++;
    charcode['\n']=charcode[EOF]=63;
}

int read_charcode()
{
    int c;
    while((c=charcode[getchar()])<0);
    return c;
}

int read_number()
{
    int c,result=0;
    while(((c=read_charcode())<53)||(c>62));
    do result=10*result+c-53;
    while(((c=read_charcode())>=53)&&(c<=62));
    while(c!=63) c=read_charcode();
    return result;
}

int mlen,message[3333];

void read_message()
{
    int c;
    mlen=0;
    while((c=read_charcode())<63)
    {
        message[mlen++]=c%4;
        c/=4;
        message[mlen++]=c%4;
        c/=4;
        message[mlen++]=c%4;
    }
}

void process_image()
{
    int lines,digits,pixel,c,m;
    lines=read_number();
    pixel=digits=m=0;
    while(lines)
    {
        if((c=read_charcode())==63)
        {
            printf("\n");
            lines--;
            continue;
        }
        pixel=10*pixel+c-53;
        if(++digits<3) continue;
        if(m<mlen) pixel=(pixel & 252) + message[m++];
        else pixel|=3;
        printf("%03d",pixel);
        pixel=digits=0;
    }
}

int main()
{
    int cases;
    init_charcodes();

    cases=read_number();
    cout<<cases<<"\n";
    while(cases--)
    {
        read_message();
        process_image();
    }
    return 0;
}
