#include<iostream>
using namespace std;
long long int pow1(long long int a,long long int b)
{
    int i,c=1;
    for(i=0; i<b; i++)
        c*=a;
    return c;
}
long long int exp1(long long int a,long long int b,long long int c)
{
    long long int P=1,T=a;
    while(b)
    {
        if(b%2==1)
            P=(P*T)%c;
        b=b/2;
        T=(T*T)%c;
    }
    return P;
}
int main()
{
    long long int f=0,a,b,c;
    cin>>a;
    while(a--)
    {
        cin>>b>>c;
        f=pow1(2,c);
        cout<<exp1(2,b-2,f)<<endl;

    }

    return 0;
}
