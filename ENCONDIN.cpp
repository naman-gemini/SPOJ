#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char line[1024];
    while(scanf("%s",line))
    {
        int len = strlen(line);
        int i = 0;
        while(i<len)
        {
            int cnt = 1;
            while(i+cnt<len && line[i+cnt] == line[i] && cnt<9)
                cnt++;
            if (cnt == 1)
            {
                printf("1");
                while(i<len)
                {
                    if (i+1<len && line[i+1] == line[i])
                        break;
                    printf("%c",line[i]);
                    if (line[i] == '1') printf("1");
                    i++;
                }
                printf("1");
            }
            else
            {
                printf("%c%c",'0'+cnt,line[i]);
                i += cnt;
            }
        }
        printf("\n");
    }
    return 0;
}
