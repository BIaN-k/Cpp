#include <stdio.h>

const int N = (1e2 + 1)*3;

int n,m;
int inform[N][21]={0};//투자 액수 정보
int DP[N][21]={0};//DP[i][j] = 돈 i원, 회사 j개일때 투자의 최대 이익
int invest[N][21]={0};//invest[i][j] = DP[i][j]에서 j번 회사에 투입한 금액
int ans[21] = {0};

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=0;j<=m;++j)
            scanf("%d",&inform[i][j]);
    }
    for(int j=1;j<=m;++j){
        for(int i=0;i<=n;++i){
            if(j==1){
                DP[i][1] = inform[i][1];
                invest[i][1] = i;
            }
            else{
                for(int k=0;k<=i;++k){
                    if(DP[i-k][j-1] + inform[k][j] > DP[i][j]){
                        DP[i][j] = DP[i-k][j-1] + inform[k][j];
                        invest[i][j] = k;
                    }
                }
            }
        }
    }
    for(int i=m,money=n;i>0;--i){
        ans[i] = invest[money][i];
        money -= invest[money][i];
    }
    printf("%d\n",DP[n][m]);
    /*for(int i=0;i<=n;++i){
        for(int j=1;j<=m;++j)
            printf("%d ",invest[i][j]);
        printf("\n");
    }*/
    for(int i=1;i<=m;++i)
        printf("%d ",ans[i]);
    return 0;
}