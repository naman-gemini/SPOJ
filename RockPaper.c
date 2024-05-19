#include<stdio.h>
#include<string.h>

int main()
{
    char lang[2][3],asset[10],point[2][6];
    struct Player
    {
        int win;
        char name[20];
        enum Source{rock,scissors,paper}source;
    }player[2] ;
    int lines,i,flag=0,game=0;
    while(1)
    {
        scanf("%s",lang[0]);
        scanf("%s",player[0].name);
        scanf("%s",lang[1]);
        scanf("%s",player[1].name);
        lines=0;
        player[0].win=0;
        player[1].win=0;
        while(lines<=100)
        {
            flag=0;
            for(i=0;i<2;i++)
            {
                scanf("%s",asset);
                if(asset[0]=='.')
                {
                flag=2;
                break;
                }
                else if(asset[0]=='-')
                {
                    flag=1;
                    break;
                }
                else if(!strcmp(lang[i],"cs"))
                {
                    if(!strcmp(asset,"Kamen"))
                    player[i].source=0;
                    else if(!strcmp(asset,"Nuzky"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Papir"))
                    player[i].source=2;
                }
                else if(!strcmp(lang[i],"en"))
                {
                    if(!strcmp(asset,"Rock"))
                    player[i].source=0;
                    else if(!strcmp(asset,"Scissors"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Paper"))
                    player[i].source=2;
                }
                else if(!strcmp(lang[i],"fr"))
                {
                    if(!strcmp(asset,"Pierre"))
                    player[i].source=0;
                    else if(!strcmp(asset,"Ciseaux"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Feuille"))
                    player[i].source=2;
                }
                else if(!strcmp(lang[i],"de"))
                {
                    if(!strcmp(asset,"Stein"))
                    player[i].source=0;
                    else if(!strcmp(asset,"Schere"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Papier"))
                    player[i].source=2;
                }
                else if(!strcmp(lang[i],"hu"))
                {
                    if(!strcmp(asset,"Ko") || !strcmp(asset,"Koe") )
                    player[i].source=0;
                    else if(!strcmp(asset,"Ollo") || !strcmp(asset,"Olloo"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Papir"))
                    player[i].source=2;
                }
                else if(!strcmp(lang[i],"it"))
                {
                    if(!strcmp(asset,"Sasso") || !strcmp(asset,"Roccia"))
                    player[i].source=0;
                    else if(!strcmp(asset,"Forbice"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Carta") || !strcmp(asset,"Rete"))
                    player[i].source=2;
                }
                else if(!strcmp(lang[i],"jp"))
                {
                    if(!strcmp(asset,"Guu"))
                    player[i].source=0;
                    else if(!strcmp(asset,"Choki"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Paa"))
                    player[i].source=2;
                }
                else if(!strcmp(lang[i],"pl"))
                {
                    if(!strcmp(asset,"Kamien"))
                    player[i].source=0;
                    else if(!strcmp(asset,"Nozyce"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Papier"))
                    player[i].source=2;
                }
                else if(!strcmp(lang[i],"es"))
                {
                    if(!strcmp(asset,"Piedra"))
                    player[i].source=0;
                    else if(!strcmp(asset,"Tijera"))
                    player[i].source=1;
                    else if(!strcmp(asset,"Papel"))
                    player[i].source=2;
                }
            }
            if(flag>=1)
            {
                if(player[0].win==1)
                strcpy(point[0],"point");
                else
                strcpy(point[0],"points");
                if(player[1].win==1)
                strcpy(point[1],"point");
                else
                strcpy(point[1],"points");
                printf("Game #%d:\n%s: %d %s \n%s: %d %s\n",++game,player[0].name,player[0].win,point[0],player[1].name,player[1].win,point[1]);
                if(player[0].win>player[1].win)
                printf("WINNER: %s\n\n",player[0].name);
                else if(player[0].win==player[1].win)
                printf("TIED GAME\n\n");
                else
                printf("WINNER: %s\n\n",player[1].name);
                break;
            }
            if(flag==0)
            {
            if(player[0].source-player[1].source==-1 || player[0].source-player[1].source==2)
            player[0].win=player[0].win+1;
            else if(player[1].source-player[0].source==-1 || player[1].source-player[0].source==2)
            player[1].win++;
            }
            lineno:
            lines++;
        }//lines
        if(flag==2)
        break;
    }//always
    return 0;
}
