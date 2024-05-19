#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

double bestto45(char p[],char q[],char r[])
{
    double temp,a,b,c;
    if(strcmp(p,"ab")==0)
        a=0;
    else
        a=atof(p);

    if(strcmp(q,"ab")==0)
        b=0;
    else
        b=atof(q);

    if(strcmp(r,"ab")==0)
        c=0;
    else
        c=atof(r);

    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    if(b<c)
    {
        temp=b;
        b=c;
        c=temp;
    }
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }

    temp=(a+b)/2;
    return(45*temp/20);

}



int main()
{
    int n,i,flag;
    double credits[6],gpa,total,final,per_attend,att_mark,asment,t_credits;
    char a1[100],a2[100],a3[100];
    scanf("%d",&n);

    while(n--)
    {
        flag=1;
        t_credits=0;
        for(i=0; i<6; i++)
            scanf("%lf",&credits[i]);

        for(i=0; i<6; i++)
        {
            scanf("%s %s %s",a1,a2,a3);
            asment=bestto45(a1,a2,a3);
            scanf("%lf",&final);
            if(final<0)
                final=0;
            scanf("%lf",&per_attend);
            if(per_attend<51.0)
                att_mark=5.0;
            else if(per_attend<61.0)
                att_mark=4.0;
            else if(per_attend<71.0)
                att_mark=3.0;
            else if(per_attend<81.0)
                att_mark=2.0;
            else if(per_attend<91.0)
                att_mark=1.0;
            else
                att_mark=0.0;
            total=asment+(final/2)+att_mark;

            if(total>=91.0)
                gpa=10.0;
            else if(total>=81.0)
                gpa=9.0;
            else if(total>=71.0)
                gpa=8.0;
            else if(total>=61.0)
                gpa=7.0;
            else if(total>50.0)
                gpa=6.0;
            else if(total==50.0)
                gpa=5.0;
            else
                gpa=0.0;

            t_credits+=gpa*credits[i];

            if(gpa==0)
                flag=0;
        }

        if(flag==0)
        {
            t_credits=t_credits/(credits[0]+credits[1]+credits[2]+credits[3]+credits[4]+credits[5]);
            printf("FAILED, %.2lf\n",t_credits);
        }
        else
        {
            t_credits=t_credits/(credits[0]+credits[1]+credits[2]+credits[3]+credits[4]+credits[5]);
            printf("PASSED, %.2lf\n",t_credits);
        }
    }
    return 0;
}
