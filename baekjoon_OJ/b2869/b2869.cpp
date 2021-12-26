#include <stdio.h>
#include <math.h>

int a,b,v,up=0,ans=0;

int main(){
    scanf("%d %d %d",&a,&b,&v);
    up = a - b;
    v -= a;
    ans = std::ceil((double)v/up) + 1;
    printf("%d",ans);
    return 0;
}