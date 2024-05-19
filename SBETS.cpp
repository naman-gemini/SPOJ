#include<cstdio>
#include<map>
#include<iostream>
using namespace std;

map<string,int> m;
int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        m.clear();
        string t1,t2;
        int s1,s2;

        for(int i=0; i<16; i++)
        {
            cin>>t1>>t2;
            cin>>s1>>s2;

            if(s1 > s2) m[t1]++;
            else m[t2]++;
        }

        map<string,int>::iterator itr;

        for(itr = m.begin(); itr!=m.end(); itr++)
        {
            if(itr->second == 4)
            {
                cout<<itr->first<<endl;
                break;
            }
        }


    }

    return 0;
}
