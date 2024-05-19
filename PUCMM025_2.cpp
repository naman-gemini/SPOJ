#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[1024];
bool divide[10];

int main()
{
    int n, res;
    while(gets(s))
    {
        n = strlen(s);
        memset(divide,false,sizeof(divide));
        for(int i = 2; i <= 9; ++i)
        {
            int rem = 0;
            for(int j = 0; j < n; ++j)
                rem = (rem*10 + (s[j]-'0')) % i;
            if(!rem) divide[i] = true;
        }
        res = 0;
        for(int i = 0; i < n; ++i)
        {
            if((s[i]-'0') == 1) res++;
            else if(divide[(s[i]-'0')]) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
