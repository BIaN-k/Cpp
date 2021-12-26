#include <stdio.h>

#include <queue>
#include <vector>
using namespace std;

int n = 0, x = 0;
vector<int> v;

bool incSort(int a, int b) {
    return a > b;
}

int main() {
    make_heap(v.begin(), v.end(), incSort);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x == 0) {
            if (!v.size())
                printf("0\n");
            else {
                printf("%d\n", v[0]);
                pop_heap(v.begin(), v.end(), incSort);
                v.pop_back();
            }
        } else {
            v.push_back(x);
            push_heap(v.begin(), v.end(), incSort);
        }
    }
    return 0;
}