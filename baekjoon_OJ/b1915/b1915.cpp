#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int N = 1e3 + 1;

typedef struct Point{
    int x,y;
}p;

typedef struct Square{
    p lu;
    p rd;
    int size;
}sq;

bool operator<(sq a,sq b){
    return a.size < b.size;
}

bool up,left,down,right;
bool LU,LD,RU,RD; //left up, left down, right up, right down
int n,m;
int M = 0;//max
int mapp[N][N] = {0};
queue<sq> q;
set<sq> s;

void square();

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%1d",&mapp[i][j]);
            if(mapp[i][j])
                q.push({{i,j},{i,j},1});
        }
    }
    square();
    printf("%d",M*M);
    return 0;
}

void square(){
    sq tmp;
    while(!q.empty()){
        up = true;
        left = true;
        down = true;
        right = true;
        tmp = q.front();
        q.pop();
        //printf("%d %d || %d %d ||",tmp.lu.x,tmp.lu.y,tmp.rd.x,tmp.rd.y);
        M = max(M, tmp.size);
        if(tmp.lu.x > 0){
            if(tmp.lu.y > 0)
                LU = mapp[tmp.lu.x - 1][tmp.lu.y - 1];
            else
                LU = false;
            if(tmp.lu.y < m - 1)
                RU = mapp[tmp.lu.x - 1][tmp.rd.y + 1];
            else
                RU = false;
        }
        else{
            LU = false;
            RU = false;
        }
        if(tmp.lu.x < n - 1){
            if(tmp.lu.y > 0)
                LD = mapp[tmp.rd.x + 1][tmp.lu.y - 1];
            else
                LD = false;
            if(tmp.lu.y < m - 1)
                RD = mapp[tmp.rd.x + 1][tmp.rd.y + 1];
            else
                RD = false;
        }
        else{
            LD = false;
            RD = false;
        }
        if(tmp.lu.x > 0){
            for(int x = tmp.lu.x - 1,y = tmp.lu.y; y <= tmp.rd.y; ++y){
                if(!mapp[x][y]){
                    up = false;
                    break;
                }
            }
        }
        else
            up = false;
        if(tmp.rd.x < n - 1){
            for(int x = tmp.rd.x + 1,y = tmp.lu.y; y <= tmp.rd.y; ++y){
                if(!mapp[x][y]){
                    down = false;
                    break;
                }
            }
        }
        else
            down = false;
        if(tmp.lu.y > 0){
            for(int x = tmp.lu.x, y = tmp.lu.y - 1; x <= tmp.rd.x; ++x){
                if(!mapp[x][y]){
                    left = false;
                    break;
                }
            }
        }
        else
            left = false;
        if(tmp.rd.y < n - 1){
            for(int x = tmp.lu.x, y = tmp.rd.y + 1; x <= tmp.rd.x; ++x){
                if(!mapp[x][y]){
                    right = false;
                    break;
                }
            }
        }
        else
            right = false;
        if(up && down && right && left && RU && RD && LU && LD){
            if(s.find({{tmp.lu.x - 1,tmp.lu.y - 1},{tmp.rd.x + 1,tmp.rd.y + 1},tmp.size + 2}) == s.end()){
                q.push({{tmp.lu.x - 1,tmp.lu.y - 1},{tmp.rd.x + 1,tmp.rd.y + 1},tmp.size + 2});
                s.insert({{tmp.lu.x - 1,tmp.lu.y - 1},{tmp.rd.x + 1,tmp.rd.y + 1},tmp.size + 2});
            }
        }
        else{
            if(up && RU && right){
                if(s.find({{tmp.lu.x - 1,tmp.lu.y},{tmp.rd.x,tmp.rd.y + 1},tmp.size + 1}) == s.end()){
                    q.push({{tmp.lu.x - 1,tmp.lu.y},{tmp.rd.x,tmp.rd.y + 1},tmp.size + 1});
                    s.insert({{tmp.lu.x - 1,tmp.lu.y},{tmp.rd.x,tmp.rd.y + 1},tmp.size + 1});
                }
            }
            if(right && RD && down){
                if(s.find({tmp.lu,{tmp.rd.x + 1,tmp.rd.y + 1},tmp.size + 1}) == s.end()){
                    q.push({tmp.lu,{tmp.rd.x + 1,tmp.rd.y + 1},tmp.size + 1});
                    s.insert({tmp.lu,{tmp.rd.x + 1,tmp.rd.y + 1},tmp.size + 1});
                }
            }
            if(down && LD && left){
                if(s.find({{tmp.lu.x, tmp.lu.y - 1},{tmp.rd.x + 1,tmp.rd.y},tmp.size + 1}) == s.end()){
                    q.push({{tmp.lu.x, tmp.lu.y - 1},{tmp.rd.x + 1,tmp.rd.y},tmp.size + 1});
                    s.insert({{tmp.lu.x, tmp.lu.y - 1},{tmp.rd.x + 1,tmp.rd.y},tmp.size + 1});
                }
            }
            if(left && LU && up){
                if(s.find({{tmp.lu.x - 1,tmp.lu.y - 1},tmp.rd,tmp.size + 1}) == s.end()){
                    q.push({{tmp.lu.x - 1,tmp.lu.y - 1},tmp.rd,tmp.size + 1});
                    s.insert({{tmp.lu.x - 1,tmp.lu.y - 1},tmp.rd,tmp.size + 1});
                }
            }
        }
    }
}

/* 1x1인 정사각형부터 탐색한뒤 2x2가 되는지 검사한후 되면 왼쪽 위, 오른쪽 아래 1의 좌표 queue에 삽입.
그 뒤로 계속 n x n인 정사각형 탐색 후 (n+1)x(n+1)이 되는지 검사한후 되면 왼쪽 위, 오른쪽 아래 1의 좌표 queue에 삽입.
set으로 정사각형 중복 체크한 후 삽입함 */