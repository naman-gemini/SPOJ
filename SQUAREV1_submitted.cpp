#include<iostream>
#include<set>
#include<cmath>
using namespace std;
int main ()
{
    set<int>s;
    for(int i=0;i<31625;++i)s.insert(i*i);
    int b,c;
    while(cin>>c)
    {
        int w=0;
        for(set<int>::iterator a=s.begin(); a!=s.end(); ++a)
        {
            if(*a>c/2)break;
            b=sqrt(c-*a);
            if(ceil(b)==floor(b)&&*a+b*b==c)++w;
        }
        cout<<w<<"\n";
    }
}
