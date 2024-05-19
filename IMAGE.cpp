#include<cstdio>



int rows,cols;
int mrow,mcol;
char grid[32][32];

void print_grid()
{
    int r,c;
    printf("%d %d %d %d",rows,cols,mrow,mcol);
    printf("\n");
    for(r = 0; r<=rows+1; r++)
    {
        for(c=0; c<=cols+1; c++)
            printf("%c",grid[r][c]);
        printf("\n");
    }
}
int read_input()
{
    scanf("%d %d %d %d",&rows,&cols,&mrow,&mcol);
    if(!rows) return 0;

    for(int i=1; i<=rows; i++) scanf("%s",grid[i]+1);
    for(int c=0; c<=cols+1; c++) grid[0][c] = grid[rows+1][c] ='.';
    for(int r=1; r<=rows; r++) grid[r][0] = grid[r][cols+1]= '.';
    return 1;

}

void mark_object()
{
    const int DR[] = {-1,-1,-1,0,0,1,1,1};
    const int DC[] = {-1,0,1,-1,1,-1,0,1};

    static int queue[32*32];
    int readptr;
    int writeptr;
    int r,c,rr,cc,d;


    grid[mrow][mcol] = 'M';

    queue[0]= 32*mrow + mcol;
    readptr = 0;
    writeptr  =1;

    while(readptr< writeptr)
    {
        r = queue[readptr]/32;
        c = queue[readptr++]%32;
        //printf("SSUP");
        //break;
        for(d=0; d<8; d++)
        {
            rr = r+ DR[d];
            cc = c + DC[d];

            if(grid[rr][cc]=='X')
            {
                grid[rr][cc]='M';
                queue[writeptr++] = 32*rr + cc;
            }
        }
    }
}

int calc_perimeter()
{
    const int DR[] = {-1,0,0,1};
    const int DC[] = {0,1,-1,0};

    int r,c,d;

    int result = 0;


    for(r = 1; r<=rows; r++) for(c=1; c<=cols; c++) if(grid[r][c]=='M')
            {
                for(d=0; d<4; d++) if(grid[r+DR[d]][c+DC[d]]=='.') result++;
            }

    return result;
}


int main()
{
    while(read_input())
    {
        mark_object();
        //   print_grid();
        printf("%d\n",calc_perimeter());
    }

    return 0;
}

