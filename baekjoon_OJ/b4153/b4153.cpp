#include <stdio.h>

int a=1,b,c;
int hyp, other;

int main(){
    while(true){
        scanf("%d %d %d",&a,&b,&c);
        if(a==0)
            return 0;
        if(a>b&&a>c){
            hyp = a*a;
            other = b*b + c*c;
        }
        if(b>a && b>c){
            hyp = b*b;
            other = a*a + c*c;
        }
        if(c>a && c>b){
            hyp = c*c;
            other = a*a + b*b;
        }
        if(hyp == other)
            printf("right\n");
        else
            printf("wrong\n");
    }
}