#include <stdio.h>

const int N = 1e2 + 1;

bool vip[N] = {0};
int F[N]={0};
int cnt=0,n=0,v=0,ans=1;

int f(int a);

int main(){
    scanf("%d %d",&n,&v);
    for(int i=0,a;i<v;++i){
        scanf("%d",&a);
        vip[a] = true;
    }
    F[0] = 1;
    F[1] = 1;
    F[2] = 2;
    vip[n+1] = true;
    for(int i=1;i<=n+1;++i){
        if(vip[i]){
            ans *= f(cnt);
            cnt = 0;
        }
        else
            ++cnt;
        //printf("%d %d\n",i,ans);
    }
    printf("%d",ans);
    return 0;
}

int f(int a){
    if(F[a])
        return F[a];
    else
        F[a]=f(a-1)+f(a-2);
    return F[a];
}