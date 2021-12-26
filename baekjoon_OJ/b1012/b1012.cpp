#include <stdio.h>

#include <algorithm>
#include <queue>
#include <vector>

const int N = 50 + 10;

bool mapp[N][N] = {0}, vis[N][N] = {0};
int T = 0, m, n, k, ans = 0;
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
std::vector<std::pair<int, int>> v;
std::queue<std::pair<int, int>> q;

void BFS(int x, int y);

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0, a, b; i < k; ++i) {
            scanf("%d %d", &a, &b);
            v.push_back({b, a});
            mapp[b][a] = true;
        }
        for (int i = 0; i < k; ++i) {
            if (!vis[v[i].first][v[i].second]) {
                ++ans;
                BFS(v[i].first, v[i].second);
            }
        }
        printf("%d\n", ans);
        v.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mapp[i][j] = false;
                vis[i][j] = false;
            }
        }
        ans = 0;
    }
    return 0;
}

void BFS(int x, int y) {
    int dx, dy;
    std::pair<int, int> tmp;
    vis[x][y] = true;
    q.push({x, y});
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            dx = tmp.first + dir[i][0];
            dy = tmp.second + dir[i][1];
            if (!vis[dx][dy] && mapp[dx][dy]) {
                vis[dx][dy] = true;
                q.push({dx, dy});
            }
        }
    }
}