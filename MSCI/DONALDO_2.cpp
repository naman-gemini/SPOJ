#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int h[20000],m[20000],s[20000],t,n,in_sec[20000],d[20000],i,j,k,I,y,z,counts,sum,case1=1;
main()
{
    scanf("%d",&t);
    while(t--)
    {
        counts=0;
        sum=0;
        y=0;
        z=0;
        scanf("%d",&n);
        if(n!=0)
        {
            for(i=0; i<n; i++)
            {
                scanf("%d:%d:%d",&h[i],&m[i],&s[i]);
                in_sec[i]=s[i]+m[i]*60+h[i]*60*60;
                // cout<<"IN_SEC :"<<in_sec[i]<<endl;
            }
            scanf("%d",&I);
            sort(in_sec,in_sec+n);
            for(i=1; i<n; i++)
                d[i-1]=in_sec[i]-in_sec[i-1]+1;

            for(i=0; i<(n-1); i++)
            {
                sum+=d[i];
                counts++;
                if(sum>I)
                {
                    sum=sum-d[i];
                    i=y;
                    y++;
                    counts-=1;
                }
                if(z<counts)
                    z=counts;
                if(z==n-1)
                    break;
            }


            printf("Case %d: %d\n",case1,z+1);
        }//ifend
        else
        {
            scanf("%d",&I);
            printf("Case %d: 0\n",case1);
        }
        case1++;
    }
//system("pause");
    return 0;
}
