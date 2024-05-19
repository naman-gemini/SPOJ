#include<cstdio>
#include<iostream>
using namespace std;


int main()
{
    string s,t;

    while(cin>>s >> t)
    {
        if(s == "*" || t == "*")
        break;

        int counter = 0;

        int size = s.size();

        bool change = false;

        for(int i=0; i<size; i++)
        {
            if(s[i] != t[i] && !change)
            {
                counter++;
                change = true;
            }

            else if(s[i] == t[i])
                change = false;


        }

        cout<<counter<<endl;

    }

    return 0;
}
