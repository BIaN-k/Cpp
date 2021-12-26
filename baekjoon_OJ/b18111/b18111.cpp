#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e3 + 1; 

int mapp[N][N]={0};
int n,m,b,block=0,time=0;
int ansTime=1e9,ansHeight=0;

int main(){
    scanf("%d %d %d",&n,&m,&b);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            scanf("%d",&mapp[i][j]);
    }
    for(int k=0;k<=256;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mapp[i][j]<k){
                    time += k - mapp[i][j];
                    block -= k - mapp[i][j];
                }
                else if(mapp[i][j]>k){
                    time += 2*(mapp[i][j] - k);
                    block += mapp[i][j] - k;
                }
            }
        }
        if(block+b<0)
            break;
        if(ansTime<time)
            break;
        if(ansTime>=time){
            ansTime = time;
            ansHeight = k;
        }
        time = 0;
        block = 0;
    }
    printf("%d %d",ansTime,ansHeight);
    return 0;
}