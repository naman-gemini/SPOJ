#include<iostream>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s,'\n'))
    {
        int i;
        int count = 0;
        s[s.size()] = ' ';
        s[s.size() + 1] = ' ';
        int flag=0;
        for(i=0;i<=s.size();i++)
        {
            if( isalpha(s[i])&&flag==0)
            {
                count++;
                flag=1;
            }
            if(isspace(s[i])&&flag==1)
        {
            flag=0;
        }

        }

        cout << count << endl;
    }

    return 0;


}
