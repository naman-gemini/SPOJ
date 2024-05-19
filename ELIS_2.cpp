#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;
typedef 

set<int> s;
set<int>::iterator it;

int main()
{
	int t,a;
	scanf("%d",&t);
	s.clear();
	for(int i=0;i<t;i++)
	{
		scanf("%d",&a);
		if(s.find(a)==s.end())
		{
			s.insert(a);
			it=s.find(a);
			it++;
			if(it!=s.end()) s.erase(it);
		}
	}
	printf("%d\n",(int)s.size());
	return 0;
}
