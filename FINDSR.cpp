#include<cstdio>
#include<math.h>
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<int> v;


void findDiv(int n)
{
    for(int i=1; i<=sqrt(n); i++)
        if(n%i==0)
        {

            v.insert(i);
            v.insert(n/i);
        }
}

string read()
{
  string s = "";
  char c;

  while ( !isalpha( c = getchar() ) );
  s += c;
  while ( isalpha( c = getchar() ) ) s += c;
  return s;
}

char inp[100005];
int main()
{


    while(1)
    {
        scanf("%s",inp);
         string s(inp);
        if(s[0] == '*') return 0;
        //cout<<s<<endl;
        v.clear();
        int sz = s.size();
        findDiv(sz);

        set<int>::iterator itr;
        for(itr = v.begin(); itr != v.end(); itr++)

        {


            int x = *itr;
            //v.pop_back();
            if(x == sz){cout<<1<<endl; break;}

            // cout<<x<<endl;


            string str = s.substr(0,x);

            // cout<<str<<endl;

            int till = sz/x;
            // cout<<till<<endl;
            int j=0;
            string res = "";

            for(j=0; j<till; j++)
                res.append(str);
            // cout<<res<<endl;
            if(res.compare(s) == 0)
            {
                cout<<sz/x<<endl;
                break;

            }

        }

    }

    return 0;


}

