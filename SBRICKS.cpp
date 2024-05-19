#include<iostream>
using namespace std;

class A
{
    int n,a[1000],i,j,k,s;

public:
    void input()
    {
        cin>>n;
        s=0;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
            s+=a[i];
        }
    }

    void calc()
    {
        j=s/n;
        k=0;
        for(i=0; i<n; i++)
        {
            if(a[i]>j)
                k=k+a[i]-j;
        }
    }
    void output()
    {
        cout<<k<<endl;
    }
};

int main()
{
    A obj;
    obj.input();
    obj.calc();
    obj.output();

    return 0;
}
