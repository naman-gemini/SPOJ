#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

char forest[12][12];



//returns true when all on fire
bool check()
{
    for(int i=1; i<12; i++)
    {
        for(int j=1; j<12; j++)
        {
            if(forest[i][j]=='T')
                return false;
        }
    }
    return true;
}

int main()
{
    //outer dots
    for(int j=0; j<12; j++)
    {
        forest[0][j]='.';
        forest[11][j]='.';
    }

    for(int i=0; i<12; i++)
    {
        forest[i][0]='.';
        forest[i][11]='.';
    }

    //loop for scanning
    for(int i=1; i<11; i++)
    {
        for(int j=1; j<11; j++)
        {
            scanf("%c",&forest[i][j]);
        }
        getchar();
    }

    for(int i=1; i<11; i++)
    {
        for(int j=1; j<11; j++)
        {
            if(forest[i][j]=='T')
            {
                if(forest[i+1][j]=='.' && forest[i-1][j]=='.' && forest[i][j+1]=='.' && forest[i][j-1]=='.')
                {
                    //printf("i=%d j=%d",i,j);
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }


//    for(int i=0; i<10; i++)
//    {
//        for(int j=0; j<10; j++)
//        {
//            printf("%c",forest[i][j]);
//        }
//        printf("\n");
//    }

    int time=0;

    vector<int> array_i;
    vector<int> array_j;

    vector<int>::iterator it;
    vector<int>::iterator it2;

    //loop for finding all positions for Fire
    while(!check())

    {
        array_i.clear();
        array_j.clear();

        for(int i=1; i<11; i++)
        {
            for(int j=1; j<11; j++)
            {
                if(forest[i][j]=='F')
                {
                    array_i.push_back(i);
                    array_j.push_back(j);
                    //printf("i=%d j=%d\n",*(array_i.end()-1),*(array_j.end()-1));
                }
            }
        }

        for(it=array_i.begin(),it2=array_j.begin(); it<array_i.end(); it++,it2++)
        {
            //printf("i=%d j=%d\n",*it,*it2);

//            for(int i=0; i<10; i++)
//            {
//                for(int j=0; j<10; j++)
//                {
//                    printf("%c",forest[i][j]);
//                }
//                printf("\n");
//            }

            if(forest[*it+1][*it2]=='T') forest[*it+1][*it2]='F';
            if(forest[*it-1][*it2]=='T') forest[*it-1][*it2]='F';
            if(forest[*it][*it2-1]=='T') forest[*it][*it2-1]='F';
            if(forest[*it][*it2+1]=='T') forest[*it][*it2+1]='F';


//            for(int i=0; i<10; i++)
//            {
//                for(int j=0; j<10; j++)
//                {
//                    printf("%c",forest[i][j]);
//                }
//                printf("\n");
//            }
        }
        time++;
        //printf("time=%d\n",time);
    }
    printf("%d\n",time);
    return 0;
}
