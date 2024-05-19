#include<stdio.h>
#include<algorithm>
using namespace std;

/*void swap(int *a, int *b)
{
  int t=*a; *a=*b; *b=t;
}
void sort(int arr[], int beg, int end)
{
  if (end > beg + 1)
  {
    int piv = arr[beg], l = beg + 1, r = end;
    while (l < r)
    {
      if (arr[l] <= piv)
        l++;
      else
        swap(&arr[l], &arr[--r]);
    }
    swap(&arr[--l], &arr[beg]);
    sort(arr, beg, l);
    sort(arr, r, end);
  }
}*/

int main()
{
    int t,n,k,i;
    long long int result,min,num[20005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);

        for(i=0;i<n;i++)
        {
            scanf("%lld",&num[i]);
        }
        if(k==1) printf("0\n");
        else
        {
            std::sort(num,num+n);
            result=num[n-1]-num[n-k];
            for(i=0;i<=n-k;i++)
            {
                min=num[i+k-1]-num[i];
                if(min<result) result=min;
            }
            printf("%lld\n",result);
        }

    }
    return 0;
}
