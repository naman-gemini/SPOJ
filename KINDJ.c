#include<stdio.h>
#include<string.h>

int main()
{
    char word[1000];
    int counter=0,i;

    while(gets(word)!=0);

    if(word[0]!=' ') counter++;
    for(i=0;word[i]!='\n';i++ )
    {
        if(word[i]==' ')
        {
            while(word[i]==' ')
            i++;

            if(i<strlen(word))
            counter++;
        }
    }
    printf("%d\n",counter);

}
