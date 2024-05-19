#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;

ll cal(string a)
{
    ll sum=1;
    int size=a.size();
    for(int i=0; i<size; i++) sum*=2;
    return sum;
}

int main()
{
    int t,n,size;
    ll sum;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        //bool flag=false;
        sum=0;
        cin>>s;
        while(s.size()>0)
        {
            sum+=cal(s);
            int max=0;

            bool flag=false;
            //cout<<"substr="<<s.substr(0,1)<<endl;
            for(int i=1; i<s.size() && s.size()>1; i++)
            {
                if(s.substr(0,i)==s.substr(s.size()-i,i))
                {
                    if(s.substr(0,i).size()>max)
                    {
                        flag=true;
                        max=s.substr(0,i).size();
                    }
                }
            }
            s=s.substr(0,max);
            //cout<<s<<endl;
            if(flag==false)
                break;
            //cout<<s<<endl;
        }
        cout<<sum<<endl;
    }
}
