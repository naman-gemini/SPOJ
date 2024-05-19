#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#define MAX 5000
using namespace std;
long long arr[MAX+5];

void init(int x)
{
    for(int i=2;i<=x;i++) arr[i] = 0;
}

int main()
{
    string s;
    int temp;
    arr[0] = 1;
    arr[1] = 1;
    while(1)
    {
        cin >> s;
        if(s == "0") break;
        int sz = s.size();
        init(sz);
        for(int i=2;i<=sz;i++)
        {
            arr[i] = arr[i-1];
            temp = (s[i-1]-'0') + (s[i-2]-'0')*10;
            if( temp <= 26 && temp > 9)
            {
                arr[i] += arr[i-2];
            }
        }
        printf("%lld\n",arr[sz]);
    }
    return 0;
}
