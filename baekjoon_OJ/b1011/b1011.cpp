#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 1;

vector<long long int> sq(N);
int dis = 0;
int T = 0,x = 0,y = 0,ans = 0;
long long int lb=0;

int main(){
    scanf("%d",&T);
    for(int i=0;i<N;++i)
        sq[i] = (long long int)i*i;
    for(int k=0;k<T;++k){
        scanf("%d %d",&x,&y);
        dis = y - x;
        lb = lower_bound(sq.begin(),sq.end(),dis) - sq.begin();
        ans = lb*2 - 1;
        if((sq[lb]+sq[lb-1])/2 >= dis)
            --ans;
        printf("%d\n",ans);
    }
    return 0;
}