#include<cstdio>
#include<string>
#include<set>
#include<iostream>
using namespace std;

int main()
{
    string line;
    int size,i;
    int x,y,len,res;
    set< pair<int,int> > set;

    while(cin>>line)
    {
        if(line=="Q") break;

        set.clear();
        size=line.size();
        res=0;
        x=0;
        y=0;

        set.insert(make_pair(x,y));

        for(i=0; i<size-1; i++)
        {
            switch (line[i])
            {
            case 'U':
            {
                y++;
                break;
            }

            case 'D':
            {
                y--;
                break;
            }

            case 'L':
            {
                x--;
                break;
            }

            case 'R':
            {
                x++;
                break;
            }

            }

            if(set.find(make_pair(x,y)) != set.end()) res++;
            set.insert((make_pair(x,y)));


        }

        printf("%d\n",res);

    }
    return 0;
}
