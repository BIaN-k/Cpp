#include <stdio.h>

const int N = 5*(1e3 + 1);

int n=0;
char arr[N] = {0};
int DP[N][N][2] = {0};
long long int ans = 0;

int main(){
    scanf("%d\n%s",&n,arr);
    for(int i=0;i<n;++i){
        if(arr[i] == 'G')
            DP[i][i][0] = 1;
        else
            DP[i][i][1] = 1;
    }
    for(int i=0;i<n;++i){
        DP[i][i+1][0] = DP[i][i][0] + DP[i+1][i+1][0];
        DP[i][i+1][1] = DP[i][i][1] + DP[i+1][i+1][1];
    }
    for(int k=2;k<n;++k){
        for(int i=0;i<n-k;++i){
            DP[i][i+k][0] = DP[i][i+k-1][0] + DP[i+1][i+k][0] - DP[i+1][i+k-1][0];
            DP[i][i+k][1] = DP[i][i+k-1][1] + DP[i+1][i+k][1] - DP[i+1][i+k-1][1];
            if(DP[i][i+k][0]==1||DP[i][i+k][1]==1)
                ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}