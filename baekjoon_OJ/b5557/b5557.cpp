/*#include <stdio.h>

const int N = 1e2 + 1;

int n=0;
int arr[N]={0};

int equal(int cnt,int val);

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&arr[i]);
    printf("%d",equal(2,arr[1]));
    return 0;
}

int equal(int cnt,int val){
    if(val<0||val>20)
        return 0;
    if(cnt==n){
        if(val==arr[n])
            return 1;
        else
            return 0;
    }
    if(arr[cnt]==0)
        return equal(cnt+1,val)*2;
    return equal(cnt+1,val-arr[cnt]) + equal(cnt+1,val+arr[cnt]);
}*/

#include <stdio.h>

const int N = 1e2 + 1;

int n=0,ans=0;
int arr[N]={0};
long long int DP[N][21]={0};

int main(){
    scanf("%d",&n);
    n-=1;
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    scanf("%d",&ans);
    DP[0][arr[0]] = 1;
    for(int i=0;i<n-1;++i){
        for(int j=0;j<21;++j){
            if(0<=j-arr[i+1])
                DP[i+1][j-arr[i+1]] += DP[i][j];
            if(j+arr[i+1]<=20)
                DP[i+1][j+arr[i+1]] += DP[i][j];
        }
    }
    /*for(int i=0;i<n;++i){
        for(int j=0;j<21;++j)
            printf("%lld ",DP[i][j]);
        printf("\n");
    }*/
    printf("%lld",DP[n-1][ans]);
    return 0;
}