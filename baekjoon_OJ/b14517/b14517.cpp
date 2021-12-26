#include <stdio.h>
#define MOD 10007

const int N = 1e3 + 1;

char s[N]={0};
int P[N][N]={0},L=0;

int main(){
    scanf("%s",s);
    for(;s[L]!=NULL;)
        ++L;
    for(int i=0;i<L;++i)
        P[i][i] = 1;
    for(int i=1;i<L;++i){
        for(int j=0;j<L-i;++j){
            if(s[j]==s[j+i])
                P[j][j+i] = (P[j+1][j+i] + P[j][j+i-1] + 1)%MOD; 
            else
                P[j][j+i] = (P[j+1][j+i] + P[j][j+i-1] - P[j+1][j+i-1] + MOD)%MOD;
        }
    }
    printf("%d",P[0][L-1]);
    return 0;
}