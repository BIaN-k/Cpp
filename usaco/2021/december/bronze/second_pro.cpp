#include <stdio.h>
#include <queue>
#include <math.h>

const int N = 1e5 + 1;

typedef struct Number{
    int val;
    int index;
}num;

typedef struct Number2{
    int val;
    int index;
}num2;

int n = 0, ans = 0;
int tp[N] = {0}, goal[N] = {0}, devi[N] = {0};//편차
std::priority_queue<num> pq;
std::priority_queue<num2> pq2;
num tmp;
num2 tmp2;

bool operator<(num a,num b){
    return a.val>b.val;
}

bool operator<(num2 a,num2 b){
    return a.val<b.val;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&goal[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&tp[i]);
    for(int i=0;i<n;++i){
        devi[i] = goal[i] - tp[i];
        if(devi[i]>0)
            pq.push({devi[i],i});
        if(devi[i]<0)
            pq2.push({devi[i],i});
    }
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        //printf("%d %d\n",tmp.val,ans);
        tmp.val = devi[tmp.index];
        if(tmp.val == 0)
            continue;
        for(int i=tmp.index;i<n;++i){
            if(devi[i]<=0)
                break;
            devi[i] -= tmp.val;
        }
        for(int i=tmp.index-1;i>=0;--i){
            if(devi[i]<=0)
                break;
            devi[i] -= tmp.val;
        }
        ans += abs(tmp.val);
    }
    while(!pq2.empty()){
        tmp2 = pq2.top();
        pq2.pop();
        tmp2.val = devi[tmp2.index];
        if(tmp2.val == 0)
            continue;
        for(int i=tmp2.index;i<n;++i){
            if(devi[i]>=0)
                break;
            devi[i] -= tmp2.val;
        }
        for(int i=tmp2.index-1;i>=0;--i){
            if(devi[i]>=0)
                break;
            devi[i] -= tmp2.val;
        }
        ans += abs(tmp2.val);
    }
    printf("%d",ans);
    return 0;
}