#include <stdio.h>

const int N = 1e2 + 1;
const int n = 12;
const int m = 6;    

char tetris[N][N] = {0};
bool vis[N][N] = {0},expVis[N][N] = {0};
int exp = 0,ans = 0;
bool chain = false;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void DFS(int x,int y,char color);

void explode(int x,int y,char color);

void move();

int main(){
    for(int i=0;i<n;++i){
        scanf("%s",tetris[i]);
        getchar();
    }
    while(true){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j]&&tetris[i][j]!='.'){
                    DFS(i,j,tetris[i][j]);
                    if(exp>=4)
                        explode(i,j,tetris[i][j]);
                    exp = 0;
                }
            }
        }
        if(chain == false)
            break;
        else{
            ++ans;
            move();
            chain = false;
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    vis[i][j] = false;
                    expVis[i][j] = false;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}

void move(){
    int dy;
    char color;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<m;++j){
            if(tetris[i][j]!='.'){
                color = tetris[i][j];
                tetris[i][j] = '.';
                dy = i;
                while(dy<n){
                    if(tetris[dy+1][j]=='.')
                        ++dy;
                    else
                        break;
                }
                tetris[dy][j] = color;
            }
        }
    }
}

void explode(int x,int y,char color){
    //printf("%d %d %c\n",x,y,color);
    int dx,dy;
    expVis[x][y] = true;
    for(int i=0;i<4;++i){
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if((0<=dx&&dx<n)&&(0<=dy&&dy<m)&&!expVis[dx][dy]&&tetris[dx][dy]==color)
            explode(dx,dy,color);
    }
    tetris[x][y] = '.';
}

void DFS(int x,int y,char color){
    //printf("%d %d %c\n",x,y,color);
    int dx,dy;
    ++exp;
    vis[x][y] = true;
    for(int i=0;i<4;++i){
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if((0<=dx&&dx<n)&&(0<=dy&&dy<m)&&!vis[dx][dy]&&tetris[dx][dy]==color)
            DFS(dx,dy,color);
    }
    if(exp>=4)
        chain = true;
}