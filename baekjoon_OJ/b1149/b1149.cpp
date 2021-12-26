#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e3 + 1;

int n = 0;
int DP[N][3] = {0};
int cost[N][3] = {0};

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d %d %d",&cost[i][0],&cost[i][1],&cost[i][2]);
    DP[0][0] = cost[0][0];
    DP[0][1] = cost[0][1];
    DP[0][2] = cost[0][2];
    for(int i=1;i<=n;++i){
        DP[i][0] = min(DP[i-1][1],DP[i-1][2]) + cost[i][0];
        DP[i][1] = min(DP[i-1][0],DP[i-1][2]) + cost[i][1];
        DP[i][2] = min(DP[i-1][0],DP[i-1][1]) + cost[i][2];
    }
    printf("%d",min(DP[n][0],min(DP[n][1],DP[n][2])));
    return 0;
}