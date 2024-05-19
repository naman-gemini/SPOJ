#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> depa,arrb,depb,arra;
bool flag[101];

int main()
{
    int t,na,nb,case_no;
    int hr,min,ttime;
    scanf("%d",&t);
    for(case_no=1; case_no<=t; case_no++)
    {
        depa.clear();
        arrb.clear();
        depb.clear();
        arra.clear();

        scanf("%d",&ttime);
        scanf("%d %d",&na,&nb);
        for(int i=0; i<na; i++)
        {
            scanf("%d:%d",&hr,&min);
            depa.push_back(hr*60+min);
            scanf("%d:%d",&hr,&min);
            arrb.push_back(hr*60+min);
        }
        for(int i=0; i<nb; i++)
        {
            scanf("%d:%d",&hr,&min);
            depb.push_back(hr*60+min);
            scanf("%d:%d",&hr,&min);
            arra.push_back(hr*60+min);
        }

        sort(depa.begin(),depa.end());
        sort(arrb.begin(),arrb.end());
        sort(depb.begin(),depb.end());
        sort(arra.begin(),arra.end());

        int count_a=0;
        int size_arr=arra.size();
        int size_dep=depa.size();

        for(int i=0; i<size_arr; i++) flag[i]=false;

        for(int i=size_dep-1; i>=0; i--)
        {
            for(int j=size_arr-1; j>=0; j--)
            {
                if(!flag[j] && (arra[j]+ttime) <= depa[i])
                {
                    count_a++;
                    flag[j]=true;
                    break;
                }
            }
        }
        na-=count_a;


        int count_b=0;
        size_arr=arrb.size();
        size_dep=depb.size();
        for(int i=0; i<size_arr; i++) flag[i]=false;

        for(int i=size_dep-1; i>=0; i--)
        {
            for(int j=size_arr-1; j>=0; j--)
            {
                if(!flag[j] && (arrb[j]+ttime) <= depb[i])
                {
                    count_b++;
                    flag[j]=true;
                    break;
                }
            }
        }
        na-=count_b;
        for(int i=0; i<101; i++) flag[i]=false;

        printf("Case #%d: %d %d\n",case_no,na,nb);

    }
    return 0;
}
