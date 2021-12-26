#include <stdio.h>

int main(){
    int k=5000;
    for(int i=0;i<100;++i){
        for(int j=0;j<50;++j,--k)
            printf("%d ",k);
        printf("\n");
    }
    return 0;
}