#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int l,h;
    string s;
    while(t--)
    {
        int n;
        cin>>n;

        l=h=0;

        for(int i=0; i<n; i++)
        {
            cin>>s;

            if(s=="lxh") l++;
            else h++;
        }

        if(l%2==0) cout<<"hhb"<<endl;
        else cout<<"lxh"<<endl;


    }

    return 0;
}
