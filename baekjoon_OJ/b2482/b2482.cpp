#include <stdio.h>

const int N = 1e3 + 1;
const int MOD = 1e9 + 3;

int n,k;
int color[N][N] = {0};

int main(){
    scanf("%d %d",&n,&k);
    for(int i=2;i<=n;++i)
        color[1][i] = i;
    for(int i=2;i<=k;++i){
        for(int j=2;j<=n;++j)
            color[i][j] = (color[i][j-1] + color[i-1][j-2]) % MOD;
    }
    printf("%d",color[k][n]);
    return 0;
}