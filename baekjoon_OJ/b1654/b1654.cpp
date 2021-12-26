#include <stdio.h>
#define MAX 1e18 + 1

const int N = 1e6 + 1;

long long int max=0;
int n,k;
int line[N]={0};

void binary_search(long long int left, long long int right);

int main(){
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; ++i)
        scanf("%d", &line[i]);
    binary_search(1,MAX);
    printf("%lld",max);
    return 0;
}

void binary_search(long long int left, long long int right){
    long long int md = (left + right)/2;
    long long int sum = 0;
    //printf("%lld %lld %lld\n",left,right,md);
    for(int i=0;i<k;++i)
        sum += line[i]/md;
    if(left>right)
        return;
    if(sum>=n){
        if(md>max)
            max = md;
        binary_search(md+1,right);
    }
    else
        binary_search(left,md-1);
}