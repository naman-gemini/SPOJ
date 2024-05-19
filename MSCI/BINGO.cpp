#include<cstdio>
#include<cctype>
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

void convert(string &a)
{
    int len=a.size();
    for(int i=0;i<len;i++)
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
        b=a&b;
        a=t;
    }
}

int main()
{
    string a,line;
    getline(cin,line);
    convert(line);
    cout<<line;

}
