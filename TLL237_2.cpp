#include<cstdio>
#include<set>
#include<iostream>
using namespace std;

multiset<int> m;
multiset<int>::iterator it;

int main()
{
    int n,t;
    char c;
    scanf("%d",&n);
    for(int i=0;i<n;i++) m.insert(0);
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='1')
        {
            t=*m.begin();
            //cout<<"t1="<<t<<endl;
            m.erase(t);
            m.insert(++t);
        }
        if(c=='2')
        {
            t=*(++m.begin());
            //cout<<"t2="<<t<<endl;
            m.erase(t);
            m.insert(++t);
        }
        for(it=m.begin();it!=m.end();it++) cout<<*it<<" "<<endl;
    }
    printf("%d %d\n",*m.begin(),*(++m.begin()));
    return 0;
}
