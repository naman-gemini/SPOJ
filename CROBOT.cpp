#include<cstdio>

int posX[100];
int posY[100];
char dir[100];



void run()
{
    int N,M;
    int a,b;
    int robot,repeat;
    char action;


    scanf("%d %d",&a,&b);
    scanf("%d %d",&N,&M);

    for(int i=1; i<=N; i++)
    {
        scanf("%d %d %c",&posX[i],&posY[i],&dir[i]);
    }

    for(int m=0; m<M; m++)
    {
        scanf("%d %c %d",&robot,&action,&repeat);

        if(action=='L' || action=='R') repeat %= 4;

        for(int rep=0; rep<repeat; rep++)
        {
            if(action=='F')
            {
                int xd =0;
                int yd = 0;
                switch(dir[robot])
                {
                case 'E':
                    xd = 1;
                    break;
                case 'N':
                    yd = 1;
                    break;
                case 'S':
                    yd = -1;
                    break;
                case 'W':
                    xd = -1;
                    break;
                }

                posX[robot] += xd;
                posY[robot] += yd;

                if(posX[robot]<=0 || posX[robot]>a || posY[robot]<=0 || posY[robot] >b)
                {
                    printf("Robot %d crashes into the wall\n",robot);
                    for (m++; m < M; m++)
                    {
                        scanf("%d %c %d",&robot,&action,&repeat);

                    }
                    return;
                }

                for(int r=1; r<=N; r++)
                {
                    if(r != robot && posX[r]==posX[robot] && posY[r]==posY[robot])
                    {
                        printf("Robot %d crashes into robot %d\n",robot,r);

                        for (m++; m < M; m++)
                        {
                            scanf("%d %c %d",&robot,&action,&repeat);

                        }
                        return;
                    }
                }


            }

            else if(action=='L')
            {
                switch(dir[robot])
                {
                case 'N':
                    dir[robot] = 'W';
                    break;
                case 'W':
                    dir[robot] = 'S';
                    break;
                case 'S':
                    dir[robot] = 'E';
                    break;
                case 'E':
                    dir[robot] = 'N';
                    break;
                }
            }
            else if(action=='R')
            {
                switch(dir[robot])
                {
                case 'N':
                    dir[robot] = 'E';
                    break;
                case 'S':
                    dir[robot] = 'W';
                    break;
                case 'E':
                    dir[robot] = 'S';
                    break;
                case 'W':
                    dir[robot] = 'N';
                    break;
                }
            }
        }

    }

    printf("OK\n");


}





int main()
{
    int k;
    scanf("%d",&k);

    for(int i=0; i<k; i++)
        run();


    return 0;
}

