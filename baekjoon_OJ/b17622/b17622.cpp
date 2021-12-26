#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAX 1e9
using namespace std;

const int N = 1e2 + 1;

typedef struct _tile{
    int x, y;
    int len;
} tile;

queue<tile> q;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool vis[N][N] = {0};
int mapp[N][N] = {0};
int tmp = 0, ans = MAX;
int n, k;

void clear();

int BFS();

bool canMove(int now, int mov, int dir); //dir 0 : up / 1 : right / 2 : down / 3 : left

int main(){
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            scanf("%d", &mapp[i][j]);
    }
    if (k == 1){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                tmp = mapp[i][j];
                for (int t = 0; t < 6; ++t){
                    if (t != tmp){
                        mapp[i][j] = t;
                        ans = min(ans, BFS());
                        clear();
                    }
                }
                mapp[i][j] = tmp;
            }
        }
    }
    else if (k == 0)
        ans = min(ans, BFS());
    if (ans == MAX)
        printf("-1");
    else
        printf("%d", ans);
    return 0;
}

void clear(){
    while(!q.empty())
        q.pop();
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            vis[i][j] = false;
    }
}

int BFS(){
    int dx, dy;
    tile tmp;
    if (canMove(0, mapp[0][0], 1))
        q.push({0, 0, 1});
    else
        return MAX;
    while (!q.empty()){
        tmp.len = q.front().len;
        tmp.x = q.front().x;
        tmp.y = q.front().y;
        vis[tmp.x][tmp.y] = true;
        q.pop();
        if (tmp.x == n - 1 && tmp.y == n - 1){
            if (canMove(1, mapp[tmp.x][tmp.y], 3))
                return tmp.len;
        }
        for (int i = 0; i < 4; ++i){
            dx = tmp.x + dir[i][0];
            dy = tmp.y + dir[i][1];
            if ((0 <= dx && dx < n) && (0 <= dy && dy < n) && canMove(mapp[tmp.x][tmp.y], mapp[dx][dy], i) && !vis[dx][dy])
                q.push({dx, dy, tmp.len + 1});
        }
    }
    return MAX;
}

bool canMove(int now, int mov, int dir){
    if (dir == 0){
        if ((mov == 0 || mov == 1 || mov == 4) && (now == 2 || now == 3 || now == 4))
            return true;
    }
    else if (dir == 1){
        if ((mov == 1 || mov == 3 || mov == 5) && (now == 0 || now == 2 || now == 5))
            return true;
    }
    else if (dir == 2){
        if ((mov == 2 || mov == 3 || mov == 4) && (now == 0 || now == 1 || now == 4))
            return true;
    }
    else{
        if ((mov == 0 || mov == 2 || mov == 5) && (now == 1 || now == 3 || now == 5))
            return true;
    }
    return false;
}