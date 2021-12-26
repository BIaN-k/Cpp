#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

const int N = 2500 + 1;

typedef struct point {
    int x, y;
} p;

int n = 0;
int sum[N][N] = {{0}};    //각 y에 대한 누적합
vector<p> stV, ndV, rdV;  //stV = 좌표압축 하기 전, ndV = y축 좌표압축 후, rdV = x, y축 좌표압축 한 후

bool Xsort(p a, p b) {
    return a.x < b.x;
}

bool Ysort(p a, p b) {
    return a.y < b.y;
}

bool XYsort(p a, p b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool YXsort(p a, p b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int main() {
    scanf("%d", &n);
    for (int i = 0, x, y; i < n; ++i) {
        scanf("%d %d", &x, &y);
        stV.push_back({x, y});
    }
    sort(stV.begin(), stV.end(), Xsort);
    for (int i = 0, x = 0; i < n; ++i) {
        if (i > 0 && stV[i].x != stV[i - 1].x)
            ++x;
        ndV.push_back({x, stV[i].y});
    }
    sort(ndV.begin(), ndV.end(), Ysort);
    for (int i = 0, y = 0; i < n; ++i) {
        if (i > 0 && ndV[i].y != ndV[i - 1].y)
            ++y;
        rdV.push_back({ndV[i].x, y});
    }
    sort(rdV.begin(), rdV.end(), XYsort);
    for (int i = 0, cnt = 0; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (rdV[cnt].x == i && rdV[cnt].y == j) {
                ++cnt;
                ++sum[i][j];
            }
            sum[i][j] = sum[i][j - 1];
        }
    }
    for
}

/*
1. x,y축 좌표압축
2. 맨 왼쪽 위부터 출발
 
  좌표가 (a,b)인 점에서의 직사각형 개수 s
   -> y좌표를 1~b까지 탐색
    -> 각각의 y좌표에서 s에 (세그먼트 트리 or 누적합)에서 (1~a,y)에 있는 점의 개수를 더해줌
*/