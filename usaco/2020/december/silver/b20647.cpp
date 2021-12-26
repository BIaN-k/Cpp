#include <stdio.h>

#include <cmath>
#include <vector>
using namespace std;

const int N = 1e5 + 1;

vector<int> line[N];
bool vis[N] = {0};
int n = 0, ans = 0;

int DFS(int start);

int main() {
    scanf("%d", &n);
    for (int i = 1, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        line[a].push_back(b);
        line[b].push_back(a);
    }
    printf("%d", DFS(1));
    return 0;
}

int DFS(int start) {
    int infect = 0;
    vis[start] = true;
    if (line[start].size()) {
        if (start == 1)
            infect = ceil(log2(line[start].size() + 1)) + line[start].size();
        else
            infect = ceil(log2(line[start].size())) + line[start].size() - 1;
    }
    printf("%d %d\n", start, infect);
    for (int i = 0; i < line[start].size(); ++i) {
        if (!vis[line[start][i]])
            infect += DFS(line[start][i]);
    }
    return infect;
}

/*
1번 농장에서 시작
1. 만약 해당 농장이 분기점일 경우 (다음 농장 개수 + 1) 보다 더 소를 복제하고 이동시킴

-> 다음 모든 농장에 소를 한마리씩은 보내야 함
   2배씩 복제하므로 log2(다음 농장 개수 + 1) 올림하면 복제할 일 수
   다음 농장의 개수가 이동시킬 일 수

-> (log2 (다음 농장 개수 + 1) + (다음 농장 개수)) 일 걸림

2. 분기점이 아닐 경우, 소를 한번 복제하고 다음 농장으로 이동시킴

-> 2일 걸림
log2 (1 + 1) + 1
= 2 -> 2번 케이스는 1번에 포함됨

  -> 해당 농장에서 걸리는 일 수는 (log2 (다음 농장 개수 + 1) + (다음 농장 개수)) 일
  

*/