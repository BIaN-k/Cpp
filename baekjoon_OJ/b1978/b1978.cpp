#include <stdio.h>

const int N = 1e3 + 1;

int n = 0, ans = 0;
bool prime[N] = {0};

int main(){
    scanf("%d", &n);
    prime[1] = true;
    for (int i = 2; i <= 500; ++i){
        for (int j = 2; i * j <= 1000; ++j)
            prime[i * j] = true;
    }
    for (int i = 0, a; i < n; ++i){
        scanf("%d", &a);
        if (!prime[a])
            ++ans;
    }
    printf("%d", ans);
    return 0;
}