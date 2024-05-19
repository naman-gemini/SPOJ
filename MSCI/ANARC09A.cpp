#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

char a[2005];

// { is 1
// } is -1

int main()
{
    int caseno=1;
    while(1)
    {
        stack<bool> mystack;
        int res=0;
        scanf("%s",a);
        if(a[0]=='-') break;

        for(int i=0; i<strlen(a); i++)
        {
            if(a[i]=='{')
                mystack.push(1);

            if(a[i]=='}')
                if(!mystack.empty())
                    mystack.pop();
                else
                {
                    res+=1;
                    mystack.push(0);

                }

        }

        printf("%d. %d\n",caseno++,res+mystack.size()/2);

        while(!mystack.empty())
        {
            mystack.pop();
        }
    }
    return 0;
}
