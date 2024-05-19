#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char s[250];
int ans;
int len;

bool solve(char a)
{
    if(a=='1') return true;
    if(a=='2') if(s[len-1]=='2' || s[len-1]=='4'|| s[len-1]=='6' || s[len-1]=='8' || s[len-1]=='0') return true;
    if(a=='3')
    {
        int sum=0;
        for(int i=0;i<len;i++) sum+=s[i]-'0';
        if(sum%3==0) return true;
    }
    if(a=='4')
    {
        if((int(s[len-1]-'0') + 2*int(s[len-2]-'0'))%4==0) return true;
    }
    if(a=='5')
    {
        if(s[len-1]=='0' || s[len-1]=='5') return true;
    }
    if(a=='6')
    {
        if(solve('3') && solve('2')) return true;
    }
//    if(a=='7')
//    {
//        int sum=0;
//        for(int i=len-1;i>=0;i-=6)
//        {
//            sum+= int(s[i]-'0') + 3*int(s[i-1]-'0') + 2*int(s[i-2]-'0') - 1*int(s[i-3]-'0') -3*int(s[i-4]-'0') -2*int(s[i-5]-'0');
//        }
//    }
    if(a=='8')
    {
        if( int(s[len-1]-'0') + 10* int(s[len-2]-'0') + 100* int(s[len-3]-'0') ) return true;
    }
    if(a=='9')
    {
        int sum=0;
        for(int i=0;i<len;i++) sum+=s[i]-'0';
        if(sum%9==0) return true;
    }
}

int main()
{
    while(scanf("%s",s)!=EOF)
    {
        ans=0;
        len=strlen(s);
        //printf("%d\n",len);
        for(int i=0; i<len; i++)
            if(solve(s[i])) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
