#include<iostream>
#include<set>
#include<utility>
using namespace std;

typedef pair<int,int> pii;

set<pii > s;
set<pii >::iterator it;

int main()
{
	s.insert(make_pair(2,3));
	s.insert(make_pair(2,1));
	s.insert(make_pair(1,5));
	s.insert(make_pair(1,1));
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<(*it).first<<(*it).second<<endl;
	}
}
