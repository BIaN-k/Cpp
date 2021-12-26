#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 1;

int mapp[N][N] = {0};
int DP[N][N] = {0};
int n,m,M=0;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            scanf("%d",&mapp[i][j]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mapp[i][j]){
                if(i==0||j==0)
                    DP[i][j] = 1;
                else
                    DP[i][j] += std::min(DP[i-1][j],std::min(DP[i-1][j-1],DP[i][j-1]));
                M = std::max(M, DP[i][j]);
            }
        }
    }
    printf("%d",M);
    return 0;
}