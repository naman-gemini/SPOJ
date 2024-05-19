#include<cstdio>
#include<algorithm>
using namespace std;

struct a_b
{
    int hr_dept;
    int min_dept;
    int hr_arr;
    int min_arr;
    int net_dept;
    int net_arr;
};

struct b_a
{
    int hr_dept;
    int min_dept;
    int hr_arr;
    int min_arr;
    int net_dept;
    int net_arr;
};

typedef struct a_b atob;
typedef struct b_a btoa;

atob a[100];
btoa b[100];

int compare_struct(const void *a,const void *b)
{
    atob *x = (atob *)a;
    btoa *y = (btoa *)b;
    return x->net_dept-y->net_dept;
}

int main()
{
    int t,na,nb,case_no;
    bool av_a,av_b;
    int count_a,count_b;
    int turn_around_time;
    scanf("%d",&t);
    for(case_no=1; case_no<=t; case_no++)
    {
        scanf("%d",&turn_around_time);
        scanf("%d %d",&na,&nb);
        for(int i=0; i<na; i++)
        {
            scanf("%d:%d %d:%d",&a[i].hr_dept,&a[i].min_dept,&a[i].hr_arr,&a[i].min_arr);
            a[i].net_dept=a[i].hr_dept*60+a[i].min_dept;
            a[i].net_arr=a[i].hr_arr*60+a[i].min_arr;
        }
        for(int i=0; i<nb; i++)
        {
            scanf("%d:%d %d:%d",&b[i].hr_dept,&b[i].min_dept,&b[i].hr_arr,&b[i].min_arr);
            b[i].net_dept=b[i].hr_dept*60+b[i].min_dept;
            b[i].net_arr=b[i].hr_arr*60+b[i].min_arr;
        }

        qsort(a,na,sizeof(atob),compare_struct);
        qsort(a,na,sizeof(atob),compare_struct);
        //for(int i=0;i<na;i++) printf("%d\n",a[i].net);

        //initialization
        count_a=0,count_b=0,av_a=false,av_b=false;
        int pointer_a=0,pointer_b=0;
        for(int i=0; i<(na+nb); i++)
        {
            a[i].net_arr
            if(av_a==false) count_a++;
            if(av_b==false) count_b++;
        }
    }
}
