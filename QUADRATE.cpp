#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int t,a,b,c,ret,tmp,k_1,k_2,k_3,sign,cnt,f=0;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        a=1,b=1,c=0,ret=0;
        cin>>s;
        k_1=s.find("x*x",0);
        //cout<<"k_1="<<k_1<<"\n";
        if (k_1!=0)
        {
            for(int i=0; i<k_1-1; i++)
            {
                ret=ret*10+(s[i]-'0');
                //cout<<ret<<"\t";
            }
            a=ret;
        }
        //cout<<"a="<<a;

        k_2=s.find("x",k_1+3);
        if(k_2==string::npos) b=0;
        else
        {
            ret=0;
            if(s[k_1+3]=='-') sign=-1;
            else sign=1;

            for(int i=k_1+4; i<k_2 && (s[i]>='0' && s[i]<'9'); i++)
            ret=ret*10+(s[i]-'0');

            if(ret!=0) b=ret*sign;
            else b=sign;
        }

        k_3=s.find('=',0);
        ret=0;
        tmp=1;
        cnt=k_3-1;
        for(cnt=k_3-1; s[cnt]>='0' && s[cnt]<='9'; cnt--)
        {
            ret=ret+(s[cnt]-'0')*tmp;
            tmp*=10;
        }

        if(s[cnt]=='-') c=-ret;
        else  c=ret;

        if((b*b-4*a*c)<0) cout<<"Imaginary roots.\n";
        else if ((b*b-4*a*c)==0) cout<<"Equal roots.\n";
        else cout<<"Distinct real roots.\n";

    }
}
