    //#include<stdio.h>
    #include<string.h>
    #include<iostream>

    int main()
    {

    int i,j;
    int s[3];
    int n[3];
    char suitn[3][10];
    int num[4];
    //scanf("%d %d %d %d %d %d",&n[0],&suitn[0],&n[1],&suitn[1],&n[2],&suitn[2]);
    cin>>n[0]>>suitn[0]>>n[1]>>suitn[1]>>n[2]>>suitn[2];

    while(1)
    {
    if(n[0] == -1 && n[1] == -1 && n[2] == -1) break;
    for(i=0; i<4; i++) num[i] = 0;

    for(i=0; i<3; i++) s[i] = 0;


    for(i=0; i<3; i++)
    {
    if(!strcmp(suitn[i],"espada"))
    {
    s[i] =0;
    num[0]++;

    }



    if(!strcmp(suitn[i],"basto"))
    {
    s[i] =1;
    num[1]++;
    }

    if(!strcmp(suitn[i],"copa"))
    {
    s[i] = 2;
    num[2]++;
    }

    if(!strcmp(suitn[i],"oro"))
    {
    s[i] = 3;
    num[3]++;
    }

    }
    int max_num = 1;
    int suit= 0;

    for(i=0; i<4; i++)
    {
    if(num[i] > 1)
    {
    max_num = num[i];
    suit = i;

    }
    }
    int cur_score= 0;
    int max1 = 0;
    if(max_num == 1)
    {

    for(j=0; j<3; j++)
    {
    if(n[j]>max1 && n[j]!= 10 && n[j]!= 11 && n[j] != 12)
    {
    max1 = n[j];
    }
    }
    cur_score = max1;
    }

    int max2= 0;
    if(max_num == 2 )
    {

    for(i=0; i<3; i++)
    {
    if(s[i] == suit && n[i] > max2 && n[i]!= 10 && n[i]!= 11 && n[i] != 12)
    {
    max2 = n[i];
    }
    }

    for(i=0; i<3; i++)
    {
    if(s[i] == suit && n[i]!= 10 && n[i]!= 11 && n[i] != 12)
    {
    cur_score += n[i];
    }
    }


    cur_score += 20;

    }



    int max31 = 0;
    int max32 = 0;
    if(max_num == 3)
    {


    for(i=0; i<3; i++)
    {
    if(n[i] > max31 && n[i]!= 10 && n[i]!= 11 && n[i] != 12)
    {
    max31 = n[i];
    }
    }

    for(i=0; i<3; i++)
    {
    if(n[i] > max32 && n[i]!= 10 && n[i]!= 11 && n[i] != 12)
    {
    if(n[i] == max31) continue;
    max32 = n[i];
    }



    }


    cur_score = 20 + max31 + max32;
    }

    int max = 0;
    for(i=0;i<3;i++)
    {
    if(n[i] > max && n[i]!= 10 && n[i]!= 11 && n[i] != 12) max = n[i];

    }
    int n_score = 0;

    if(max == 7) n_score = 26 + max;
    else n_score = 27 + max;
    //printf("%d",n_score-cur_score);
    cout << n_score - cur_score << endl;

    //scanf("%d %d")
    cin>>n[0]>>suitn[0]>>n[1]>>suitn[1]>>n[2]>>suitn[2];
    }

    }
