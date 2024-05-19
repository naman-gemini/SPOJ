#include<cstdio>
#include<vector>
using namespace std;


vector<int> v;
vector<int> frames;
vector<int>::iterator it;

void take_input()
{
    int counter;
    int d1,d2,d3;
    v.clear();
    counter=9;
    //Taking 18 inputs(2 for each frame) taking just 1 input in case first input is 10
    while(counter>0)
    {
        scanf("%d",&d1);
        v.push_back(d1);
        if(d1!=10)
        {
            scanf("%d",&d2);
            v.push_back(d2);
        }
        counter--;
    }

    scanf("%d %d",&d1,&d2);
    v.push_back(d1);
    v.push_back(d2);
    if(d1==10 || d1+d2==10)
    {
        scanf("%d",&d3);
        v.push_back(d3);
    }
}

void print_vector(vector<int> v)
{
    for(it=v.begin(); it!=v.end(); it++) printf("%d ",*it);
    printf("\n");
}

int main()
{
    int t,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        take_input();
        frames.clear();
        for(int i=0; i<=v.size(); i++) frames.push_back(0);
        //print_vector(v);
        //print_vector(frames);
        int i=1;
        for(it=v.begin(); i<=10; it++)
        {
            if(*it==10)
            {
                frames[i]=10+*(it+1)+*(it+2);
                i++;
            }
            else if(*it+*(it+1)==10)
            {
                frames[i]=10+*(it+2);
                i++;
                it++;
            }
            else
            {
                frames[i]=*it+*(it+1);
                i++;
                it++;
            }
        }

        for(it=frames.begin(); it!=frames.end(); it++) ans+=*it;
        printf("%d\n",ans);
    }
    v.clear();
    frames.clear();
    return 0;
}
