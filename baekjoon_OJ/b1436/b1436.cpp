#include <string>
#include <stdio.h>
using namespace std;

int n = 0, cnt = 0, num = 665;
string s;

int main(){
    scanf("%d", &n);
    while(true){
        ++num;
        s = to_string(num);
        if (s.find("666") != -1)
            ++cnt;
        if (cnt == n)
            break;
    }
    printf("%d", num);
    return 0;
}