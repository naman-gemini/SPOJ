#include<cstdio>
#include<cctype>
#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

void convert(string &a)
{
    int len=a.size();
    for(int i=0; i<len; i++)
    {
        if(isalpha(a.at(i))) a.at(i)=tolower(a.at(i));
        else a.at(i)=' ';
    }
}

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    int game=0,ans=0,x;
    string line,sub;
    string::iterator it;
    set<string> s;
    while(getline(cin,line))
    {
        convert(line);
        //cout<<line<<endl;
        stringstream ss(line);
        while(ss>>sub)
        {
            if(sub=="bullshit")
            {
                game++;
                ans+=s.size();
                s.clear();
            }
            else s.insert(sub);
        }
    }
    x=gcd(ans,game);
    printf("%d / %d\n",ans/x,game/x);
    return 0;
}
