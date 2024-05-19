#include<stdio.h>
#include<stdlib.h>

struct myStruct
{
    int x;
    float y;
};

void fx(struct myStruct *b)
{
    struct myStruct *t;
    t=(struct myStruct*)malloc(sizeof(struct myStruct));
    t->x=4;
    t->y=5.6;
    //b->x=9;
    //b->y=9.9;
   // *b=*t;
    //b->x=t->x;
    //b->y=t->y;

}

int main()
{
    struct myStruct *b=NULL;
    //struct myStruct c;
    //b=(struct myStruct*)malloc(sizeof(struct myStruct));
//    b->x=2;
//    b->y=3.4;
//    c.x=3;
//    c.y=3.5;
//    printf("%d %f\n",b->x,b->y);
//    printf("%d %f\n",(&c)->x,(&c)->y);
    fx(b);
    //fx(&c);
    //printf("%d %f\n",b->x,b->y);
//    printf("%d %f\n",(&c)->x,(&c)->y);
    return 0;
}
