#include <stdio.h>
#include <algorithm>
#include <math.h>
#define ll long long int

const int N = 1e6 + 1;

int n,m,nowTree = 0,h=0,ans = 0;
int tree[N] = {0};

bool lessSort(int a,int b){
    return a > b;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&tree[i]);
    std::sort(tree,tree+N,lessSort);
    ans = tree[0];
    while(true){
        while(tree[nowTree] == tree[nowTree + 1])
            ++nowTree;
        h = tree[nowTree] - tree[nowTree + 1];
        if((ll)(nowTree + 1) * h < m){
            m -= (nowTree + 1) * h;
            ans -= h;
        }
        else if((ll)(nowTree + 1) * h == m){
            ans -= h;
            break;
        }
        else{
            ans -= std::ceil((double)m / (nowTree + 1));
            break;
        }
        ++nowTree;
    }
    printf("%d",ans);
    return 0;
}