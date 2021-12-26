#include <stdio.h>
using namespace std;

const int N = 20 + 1;

typedef struct _Block{
    int shark;
    int num;
    int smell;
}block;

typedef struct _Shark{
    int x,y;
    int dir;
    int prior[4][4];//priority
    bool removed;
}_shark;

int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,k,cnt=0;
bool mov=false,end=true;
block mapp[N][N];
_shark shark[N*N];

void Simul();

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&mapp[i][j].shark);
            mapp[i][j].num = mapp[i][j].shark;
            if(mapp[i][j].shark){
                shark[mapp[i][j].num].x = i;
                shark[mapp[i][j].num].y = j;
                mapp[i][j].smell = k;
            }
        }
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&shark[i].dir);
        shark[i].dir -= 1;
    }
    for(int i=1;i<=m;++i){
        for(int j=0;j<4;++j){
            for(int k=0;k<4;++k){
                scanf("%d",&shark[i].prior[j][k]);
                shark[i].prior[j][k] -= 1;
            }
        }
    }
    Simul();
    printf("%d",cnt);
    return 0;
}

void Simul(){
    int dx=0,dy=0;
    while(cnt<1000){
        for(int i=1;i<=m;++i){
            if(shark[i].removed == true)
                continue;
            for(int j=0;j<4;++j){
                dx = shark[i].x + d[shark[i].prior[shark[i].dir][j]][0];
                dy = shark[i].y + d[shark[i].prior[shark[i].dir][j]][1];
                if((0<=dx&&dx<n)&&(0<=dy&&dy<n)&&mapp[dx][dy].num==0){
                    mapp[shark[i].x][shark[i].y].shark = 0;
                    shark[i].dir = shark[i].prior[shark[i].dir][j];
                    mov = true;
                    shark[i].x = dx;
                    shark[i].y = dy;
                    if(mapp[dx][dy].shark == 0)
                        mapp[dx][dy].shark = i;
                    else if(mapp[dx][dy].shark < i)
                        shark[i].removed = true;
                    else if(mapp[dx][dy].shark > i){
                        shark[mapp[dx][dy].shark].removed = true;
                        mapp[dx][dy].shark = i;
                    }
                    break;
                }
            }
            if (!mov){
                for (int j = 0; j < 4; ++j){
                    dx = shark[i].x + d[shark[i].prior[shark[i].dir][j]][0];
                    dy = shark[i].y + d[shark[i].prior[shark[i].dir][j]][1];
                    if ((0 <= dx && dx < n) && (0 <= dy && dy < n) && mapp[dx][dy].num == i){
                        mapp[shark[i].x][shark[i].y].shark = 0;
                        shark[i].dir = shark[i].prior[shark[i].dir][j];
                        mov = true;
                        shark[i].x = dx;
                        shark[i].y = dy;
                        if(mapp[dx][dy].shark == 0)
                            mapp[dx][dy].shark = i;
                        else if (mapp[dx][dy].shark < i)
                            shark[i].removed = true;
                        else if (mapp[dx][dy].shark > i){
                            shark[mapp[dx][dy].shark].removed = true;
                            mapp[dx][dy].shark = i;
                        }
                        break;
                    }
                }
            }
            mov = false;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(mapp[i][j].smell>0){
                    mapp[i][j].smell -= 1;
                    if(mapp[i][j].smell == 0)
                        mapp[i][j].num = 0;
                }
                if(mapp[i][j].shark){
                    mapp[i][j].num = mapp[i][j].shark;
                    mapp[i][j].smell = k;
                }
                if(mapp[i][j].shark>1)
                    end = false;
            }
        }
        /*for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                printf("%d %d %d  ",mapp[i][j].shark,mapp[i][j].num,mapp[i][j].smell);
            }
            printf("\n");
        }
        printf("\n");*/
        ++cnt;
        if(end == true)
            return;
        end = true;
    }
    cnt = -1;
}