#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 1;

int n,K,T,ans=0;
int DP[N][N][10][10] = {{{{0}}}};//0번 = 왼쪽에서 옴 , 1번 위에서 옴

int main(){
    scanf("%d",&T);
    for(int t=0;t<T;++t){
        char mapp[N][N] = {0};
        scanf("%d %d",&n,&K);
        for(int i=0;i<n;++i)
            scanf("\n%s",mapp[i]);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<=3;++k){
                    DP[i][j][k][0] = 0;
                    DP[i][j][k][1] = 0;
                }
            }
        }
        DP[0][0][0][0] = 1;
        DP[0][0][0][1] = 1;
        for(int j=1;j<n;++j){
            if(mapp[0][j] == '.')
                DP[0][j][0][0] = DP[0][j-1][0][0];
        }
        for(int i=1;i<n;++i){
            if(mapp[i][0] == '.')
                DP[i][0][0][1] = DP[i-1][0][0][1];
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<n;++j){
                if(mapp[i][j] == '.'){
                    for(int k=1;k<=3;++k){
                        DP[i][j][k][0] += DP[i][j-1][k-1][1] + DP[i][j-1][k][0];
                        DP[i][j][k][1] += DP[i-1][j][k][1] + DP[i-1][j][k-1][0];
                    }
                }
            }
        }
        for(int k=1;k<=K;++k)
            ans += DP[n-1][n-1][k][0] + DP[n-1][n-1][k][1];
        printf("%d\n",ans);
        ans = 0;
        n=0;
        K=0;
    }
    return 0;
}