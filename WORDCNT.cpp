#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n;
    char input_str[20200];
    char *pch;
    scanf("%d\n",&n);
    //getchar();
    while(n--)
    {
        int len = 0, pch_len = -1, maxcount=0,count=1;
        //cin>>input_str;
        //scanf("%s",input_str);
        gets(input_str);
        //fgets(input_str,20200,stdin);
        pch = strtok(input_str," \n\t\r");
        while(pch!=NULL)
        {
            len = strlen(pch);
            if(len==pch_len) count++;
            else count=1;

            if(count>maxcount) maxcount = count;
            pch_len=len;


            pch = strtok(NULL," \n\t\r");
        }
        printf("%d\n",maxcount);
    }
    return 0;
}
