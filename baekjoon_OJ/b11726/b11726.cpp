#include <stdio.h>
#define MOD 10007

const int N = 1e3 + 1;

int DP[N]={0};
int n=0;

int main(){
    DP[1] = 1;
    DP[2] = 2;
    scanf("%d",&n);
    for(int i=3;i<=n;++i)
        DP[i] = (DP[i-1] + DP[i-2])%MOD;
    printf("%d",DP[n]);
    return 0;
}