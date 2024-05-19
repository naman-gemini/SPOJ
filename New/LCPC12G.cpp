//multiplying matrices
#include<cstdio>
#include<iostream>
#define DEBUG if(0)

using namespace std;
typedef long long ll;

ll chromosomes[111];
const ll H= 1000000007;

int N;

void multiply(ll init[][111],ll final[][111]){
    ll aux[N][N];
    DEBUG cout << "here" << endl;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) aux[i][j]=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
             for(int k=0;k<N;k++)
                aux[i][j]+= ((init[i][k]%H)*(final[k][j]%H))%H;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
               final[i][j]=aux[i][j];

}

void binary_exponentation(ll M[][111],long long exponent){
    ll base[111][111];
    ll result[111][111];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) base[i][j]=M[i][j],result[i][j]=0LL;
    for(int i=0;i<N;i++) result[i][i]=1LL;
    while(exponent!=0){
        if(exponent%2!=0)
            multiply(base,result);
        multiply(base,base);
        exponent/=2;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            M[i][j]=result[i][j];

//
//    printf("here\n");
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++)
//             printf("%lld ",M[i][j]);
//        putchar('\n');
//            }
}

int main(){
    int t;ll exponent;
    int a,b;
    ll final[111][111];
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%lld%d",&exponent,&N);
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) final[i][j]=0LL;
        for(int i=0;i<N;i++) scanf("%lld",&chromosomes[i]);
        for(int i=0;i<N;i++){
            scanf("%d",&a);
            for(int j=0;j<a;j++){
                scanf("%d",&b);
                final[i][b]=1LL;
            }
        }

//        if(exponent==0){
//            printf("%d. ",cs);
//            for(int i=0;i<N;i++)
//                printf("%lld ",chromosomes[i]);
//            putchar('\n');
//        }
//        else{
            ll ans[N];
            for(int i=0;i<N;i++) ans[i]=0LL;

            binary_exponentation(final,exponent);
//            for(int i=0;i<N;i++){
//                for(int j=0;j<N;j++)
//                            printf("%lld ",final[i][j]);
//                    putchar('\n');
//            }
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++){
                    ans[i]+=((final[i][j]%H)*(chromosomes[j]%H))%H;

                }
            printf("%d. ",cs);
            for(int i=0;i<N;i++)
                printf("%lld ",ans[i]%H);
            putchar('\n');



    }
    return 0;
}


