#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
using namespace std;
string p[1111];
void pow5(int n)
{
    string result = "1";
    for(int i = 1; i < n; i++)
    {
        int carry = 0;
        for(int j = result.size()-1; j >= 0; j--)
        {
            int d = (result[j]-'0') * 5 + carry;
            if(d>9)
            {
                carry = d / 10;
                d = d % 10;
            }
            else
                carry = 0;
            result[j] = d + '0';
        }
        if(carry)
            result.insert(0, 1, carry + '0');
        int diff = i - result.size();
        if(diff)
            result.insert(0, diff, '0');
        p[i] = result;
    }
}

int main()
{
    pow5(1000);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n == 1)
            printf("1\n");
        else
            cout << "0." + p[n-1] << endl;
    }
    return 0;
}

