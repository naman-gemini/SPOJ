#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string s;
int n;
vector<pair<string,int> > v;
typedef pair<string,int> si;
vector<pair<string,int> >::iterator it;

bool cmp(const si &a, const si &b)
{

    if(a.second==b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{
    while(cin>>s>>n)
    {

        v.push_back(make_pair(s,n));
    }

    sort(v.begin(),v.end(),cmp);

    for(it=v.begin();it<v.end();it++)
    cout<<it->first<<endl;
    return 0;
}
