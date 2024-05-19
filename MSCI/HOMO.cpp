#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int main()
{
    int t;
    int cs=0,cd=0;
    map<int,int>a;
    char s[20];
    char ans[20]="neither";
    int n;
    cin>>t;
    cin>>s>>n;
    cout<<"neither"<<endl;

    if(s[0]=='i')
        a[n]++;

    for(int i=1; i<t; i++)
    {
        cin>>s>>n;
        if(s[0]=='i')
        {
            if(a[n]==0)
                cd++;
            a[n]++;
            if(a[n]>1)
                cs ++;
        }
        else
        {
            if(a[n]==0)
            {
                cout<<ans<<endl;
                continue;
            }
            else
            {
                if(a[n]>1)
                    cs--;
                a[n]--;
                if(a[n]==0)
                    cd--;
            }
        }


        if(cs>=1&&cd>=1)
        {
            cout<<"both"<<endl;
            strcpy(ans,"both");
        }
        else if(cs>=1&&cd==0)
        {
            cout<<"homo"<<endl;
            strcpy(ans,"homo");

        }
        else if(cs==0&&cd>=2)
        {
            cout<<"hetero"<<endl;
            strcpy(ans,"hetero");

        }
        else
        {
            cout<<"neither"<<endl;
            strcpy(ans,"neither");
        }
    }

    //system("pause");
    return 0;
}
