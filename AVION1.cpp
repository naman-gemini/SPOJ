#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char s[20];
    size_t found;
    string res;
    int n[5];
    int pos=0;
    int count = 0;
    for(int i=0; i<5; i++)
    n[i] = 0;
    for(int i=0; i<5; i++)
    {
        gets(s);
        res = s;
        found = res.find("FBI");
        if(found != string::npos)
        {
            n[i]++;
            count++;
        }

    }

    if(count == 0) cout<<"HE GOT AWAY!"<<endl;

    for(int i=0; i<5; i++)
    {
        if(n[i] != 0)  cout<<i+1<<' ';
    }


    return 0;
}
