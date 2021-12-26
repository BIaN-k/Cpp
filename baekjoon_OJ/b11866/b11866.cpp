#include <stdio.h>
#include <vector>
using namespace std;

int n, k, pos = -1, stand = 0;
vector<int> j;
vector<int>::iterator st = j.begin();

int main(){
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        j.push_back(i);
    printf("<");
    stand = n;
    while (!j.empty()){
        pos += k;
        while (pos >= stand && stand != 0){
            pos %= stand;
            stand = j.size();
        }
        printf("%d, ", j[pos]);
        st = j.erase(st + pos);
    }
    printf(">");
    return 0;
}