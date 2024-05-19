#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector <long long> s;
    s.push_back(1);

    for(int i=1;i<=150;i++)
    {
        s.push_back(s[i-1]*(4*i-2)/(i+1));
    }

    int t;

    while(1)
    {
        scanf("%d",&t);
        //cout<<s[t]<<"\n";
        printf("%lld\n",s[t]);
    }
    return 0;
}
