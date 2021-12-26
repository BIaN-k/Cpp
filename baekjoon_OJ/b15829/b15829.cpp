#include <stdio.h>

const int N = 1e2 + 1;
const int MOD = 1234567891;

char arr[N]={0};
int L=0;
long long int H=0;
long long int r = 1;

int main(){
    scanf("%d",&L);
    scanf("\n%s",arr);
    for(int i=0;i<L;++i){
        H += r*(arr[i]-'a'+1);
        H%=MOD;
        r*=31;
        r%=MOD;
    }
    printf("%d",H);
    return 0;
}