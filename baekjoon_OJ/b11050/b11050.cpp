#include <stdio.h>

int n,k;

int fac(int a){
    int s=1;
    for(int i=2;i<=a;++i)
        s*=i;
    return s;
}

int main(){
    scanf("%d %d",&n,&k);
    printf("%d",fac(n)/(fac(k)*fac(n-k)));
    return 0;
}