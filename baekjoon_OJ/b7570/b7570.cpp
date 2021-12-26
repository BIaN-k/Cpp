#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e6 + 1;

int n=0,M=0;
int arr[N]={0};
int cont[N]={0};//continuous arr, 가장 긴 연속 증가 수열 ex) 1,2,3,4 / 5,6,7 등

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;++i)
        cont[arr[i]] = cont[arr[i]-1] + 1;
    for(int i=0;i<n;++i)
        M = max(M,cont[arr[i]]);
    printf("%d",n-M);
    return 0;
}