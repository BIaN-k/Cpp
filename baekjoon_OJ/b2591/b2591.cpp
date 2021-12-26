#include <stdio.h>

const int N = 1e2 + 1;

char arr[N] = {0};
long long int ans = 1;
int len = 0, ten = 0, one = 0;
int dp = 1; //arr[i]*10 + arr[i+1]<=34가 성립하는 i의 최대 연속값 + 1 ex) 2 3 1 -> dp = 2 + 1 = 3
int fibo[N]={0};

int main(){
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i=2;i<=41;++i)
        fibo[i] = fibo[i-1] + fibo[i-2];
    scanf("%s", arr);
    for (; arr[len] != NULL;)
        ++len;
    ten = (arr[0] - '0') * 10;
    one = arr[1] - '0';
    for (int i = 1; i < len; ++i){
        //printf("%d %d %d %d\n",ten,one,dp,ans);
        if(one==0){
            ans *= fibo[dp-1];
            dp = 1;
            ten = (arr[i + 1] - '0') * 10;
            one = arr[i + 2] - '0';
            ++i;
            continue;
        }
        else if(ten + one <= 34)
            ++dp;
        else{
            ans *= fibo[dp];
            dp = 1;
        }
        ten = one * 10; 
        one = arr[i + 1] - '0';
    }
    ans *= fibo[dp];
    printf("%lld", ans);
    return 0;
}