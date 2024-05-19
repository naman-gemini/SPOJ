#include<iostream>

using namespace std;


int main()
{
    char inp[222];
    int x,y;
    char dir;
    while(scanf("%s",inp)==1)
    {
        x = 310;
        y=420;
        dir = 'E';
        printf("300 420 moveto\n");
        printf("310 420 lineto\n");
        for(int i=0; inp[i]; i++)
        {
            if(inp[i]=='V')
            {
                switch(dir)
                {
                case 'E':
                    dir='N';
                    y+=10;
                    break;
                case 'N':
                    dir='W';
                    x-=10;
                    break;
                case 'W':
                    dir = 'S';
                    y -= 10;
                    break;
                case 'S':
                    dir='E';
                    x+=10;
                    break;
                }
            }

            else if(inp[i]=='A')
            {
                switch(dir)
                {
                case 'E':
                    dir = 'S';
                    y -= 10;
                    break;
                case 'S':
                    dir = 'W';
                    x -= 10;
                    break;
                case 'W':
                    dir = 'N';
                    y+=10;
                    break;
                case 'N':
                    dir = 'E';
                    x += 10;
                    break;
                }
            }

            printf("%d %d lineto\n",x,y);
        }

        printf("stroke\n");
        printf("showpage\n");

    }


    return 0;
}

