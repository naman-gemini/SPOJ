#include<stdio.h>
int main()
        {
        int a[10001],b[10001];
        int i,j;
        int n,m;
        while(scanf("%d",&n)&&n)
                {
                for(i=0;i<n;i++)        scanf("%d",&a[i]);
                scanf("%d",&m);
                for(j=0;j<m;j++)
                        scanf("%d",&b[j]);
                int c[10001]={0},d[10001]={0};
                i=j=0;
                int k=0,l=0;
                int sum=0;
                for(i=0,j=0;i<n&&j<m;)
                        {
                        int flag=0;
                        if(a[i]==b[j])
                                {
                                c[k]+=a[i];
                                d[l]+=b[j];
                                //sum=0;
                                k++;
                                l++;
                                flag=1;
                                i++;j++;
                        }


                        if(a[i]<b[j]&&!flag) {

                        c[k]+=a[i];
                        i++;
                        }
                        else if(a[i]>b[j]&&!flag){
                         d[l]+=b[j];

                         j++;
                         }
                        //if(a[i]==b[j]) i++;j++;

                }
                if((!i)||(!j)) i=j=0;
                for(;j<m;j++) d[l]+=b[j];
                for(;i<n;i++) c[k]+=a[i];
                k++;
                l++;
                for(i=0,j=0;i<k&&j<l;i++,j++)
                        {
                        if(c[i]>d[j]) sum+=c[i];
                        else sum+=d[j];
                        }
                #ifdef DEB
                for(i=0;i<k;i++)
                        printf("%d\t",c[i]);
                puts("");
                for(j=0;j<l;j++)
                        printf("%d\t",d[j]);
                puts("");
                #endif
                printf("%d\n",sum);
                }
        return 0;
        }
