#include <stdio.h>

int a, b, gcd, lcm;

int GCD(int a, int b);

int main(){
    scanf("%d %d", &a, &b);
    gcd = GCD(a, b);
    lcm = (a * b) / gcd;
    printf("%d\n%d", gcd, lcm);
    return 0;
}

int GCD(int a, int b){
    int r = -1;
    while (true)
    {
        r = a % b;
        if (r == 0)
            return b;
        a = b;
        b = r;
    }
}