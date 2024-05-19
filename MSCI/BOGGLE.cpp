#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

char s[100][100];

int main()
{
    int n;
    scanf("%d",&n);
    string a;
    for(int i=0;i<n;i++)
    {
        cin.getline(s[i],256);
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
}
