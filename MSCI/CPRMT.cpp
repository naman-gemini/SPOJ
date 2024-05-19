#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

char s1[1001],s2[1001];
vector<char> v1;
vector<char> v2;
vector<char> ans;
vector<char>::iterator it;
vector<char>::iterator it2;

int main()
{
    while(scanf("%s\n%s",s1,s2)!=EOF)
    {
        for(int i=0; i<strlen(s1); i++)
        {
            v1.push_back(s1[i]);
            //printf("%c",s1[i]);
        }

        for(int i=0; i<strlen(s2); i++)
        {
            v2.push_back(s2[i]);
            //printf("%c",s2[i]);
        }

        if(v1.size()>v2.size())
        {
            for(it=v1.begin(); it<v1.end(); it++)
            {
                for(it2=v2.begin(); it2<v2.end(); it2++)
                {
                    if(*it==*it2)
                    {
                        ans.push_back(*it);
                        v2.erase(it2);
                        break;
                    }
                }
            }
        }
        else
        {
            for(it=v2.begin(); it<v2.end(); it++)
            {
                for(it2=v1.begin(); it2<v1.end(); it2++)
                {
                    if(*it==*it2)
                    {
                        ans.push_back(*it);
                        v1.erase(it2);
                        break;
                    }
                }
            }

        }
        sort(ans.begin(),ans.end());
        for(it=ans.begin(); it<ans.end(); it++)
            printf("%c",*it);
        printf("\n");

        for(int i=0; i<1002; i++)
        {
            s1[i]='\0';
            s2[i]='\0';
        }
        v1.clear();
        v2.clear();
        ans.clear();
    }
    return 0;
}
