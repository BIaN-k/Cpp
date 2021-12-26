#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e3 + 1;

int cnt=0;
int n,m;
int height[N][N] = {0},path[N][N] = {0};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int DFS(int x,int y);

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            scanf("%d",&height[i][j]);
    }
    for(int i=0;i<n;++i)
        fill(path[i],path[i]+m,-1);
    path[n-1][m-1] = 1;
    printf("%d",DFS(0,0));
    printf(" %d\n",cnt);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            printf("%d ",path[i][j]);
        printf("\n");
    }
    return 0;
}

int DFS(int x,int y){
    ++cnt;
    printf("%d %d\n",x,y);
    path[x][y] = 0;
    int dx,dy;
    for(int i=0;i<4;++i){
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if((0<=dx&&dx<n)&&(0<=dy&&dy<m)&&height[x][y]>height[dx][dy]){
            if(path[dx][dy]!=-1)
                path[x][y] += path[dx][dy];
            else
                path[x][y] += DFS(dx,dy);
        }
    }
    return path[x][y];
}