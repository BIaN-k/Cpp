#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;

int arr[N];
int n=0,ans=1,prevNum=0,IncDp=0,DecDp=0;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    prevNum = arr[0];
    IncDp = 1;
    DecDp = 1;
    for(int i=1;i<n;++i){
        if(arr[i]<prevNum){
            ++DecDp;
            IncDp = 1;
        }
        else if(arr[i]==prevNum){
            ++IncDp;
            ++DecDp;
        }
        else{
            ++IncDp;
            DecDp = 1;
        }
        prevNum = arr[i];
        ans = max(ans,max(IncDp,DecDp));
    }
    printf("%d",ans);
    return 0;
}