//algo: ad-hoc

#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

map<string,int> m_name;
bool table[2105][2105];

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
            if(i==j) table[i][j]=1;
            else table[i][j]=0;
    }
}

int main()
{
    int n,m;
    int a,b;
    string name,name1,name2;
    while(scanf("%d %d",&n,&m) && n && m)
    {
        init(n);
        m_name.clear();
        for(int i=1; i<=n; i++)
        {
            cin>>name;
            m_name.insert(make_pair(name,i));
        }

        for(int i=1; i<=m; i++)
        {
            cin>>name1>>name2;
            a=m_name[name1];
            b=m_name[name2];
            //cout<<a<<b<<endl;

            table[a][b]=table[b][a]=1;
            //cout<<table[a][b]<<" "<<table[b][a]<<endl;

            for(int i=1; i<=n; i++)
            {
                if(table[i][a]==1) table[i][b]=1;
                if(table[i][b]==1) table[i][a]=1;
            }
        }

        bool flag=true;

        for(int i=1; i<=n; i++)
        {
            if(flag==false) break;
            for(int j=1; j<=n; j++)
            {
                if(flag==false) break;
                if(table[i][j]==0) flag=false;
            }
        }

        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
