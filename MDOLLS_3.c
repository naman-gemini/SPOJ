#include <cstdio>
#define MAXM (20001)

struct doll
{
    int w,h;
};

struct doll dolls[MAXM];
int size[MAXM+1];
int anti_chain_size;

int cmp(void *a,void *b)
{
  struct doll* ta=((struct doll*)a);
  struct doll* tb=((struct doll*)b);


  if (ta->w != tb->w)
    return ta->w - tb->w;
  return tb->h  - ta->h;

}

int main()
{
  int n,m,i,j;
  scanf("%d",&n);
  while(n--)
  {

    scanf("%d",&m);
    for (i=0;i<m;i++)
      scanf("%d %d",&dolls[i].w,&dolls[i].h);
    qsort(dolls,m,sizeof(struct doll),cmp);
    anti_chain_size=0;
    for (i=0;i<m;i++)
    {
      int hi=anti_chain_size;
      int lo=0;
      while (hi>lo)
      {
        int mid=(hi+lo)/2;
        if (size[mid]>=dolls[i].h)
          lo=mid+1;
        else
          hi=mid;
      }
      size[lo]=dolls[i].h;
      anti_chain_size+=(lo==anti_chain_size);
    }
    printf("%d\n",anti_chain_size);
  }
  return 0;
}
