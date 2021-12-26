#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 4 + 1;

typedef struct _fish{
    int x,y;
    int num;//번호
    int dir;//방향
}fish;

typedef struct _state{
    int tmpMap[N][N];//현재 맵 정보
    fish f[18];//현재 물고기들 위치, 17번 : 상어
    int cnt;//상어가 현재 먹은 물고기들의 번호 합
}state;

state Origin,tmp;
int orimap[N][N]={0};
int ans=0;//최대 번호 합
int d[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
deque<state> q;
int sharkx,sharky;

void BFS();

void init();

int main(){
    for(int i=0,a,b;i<4;++i){
        for(int j=0;j<4;++j){
            scanf("%d %d",&a,&b);
            Origin.f[a] = {i,j,a,b-1};
            Origin.tmpMap[i][j] = a;
            if(i==0&&j==0){
                Origin.f[a].dir = -1;
                Origin.tmpMap[i][j] = 17;
                Origin.cnt += a;
                Origin.f[17] = {0,0,17,b-1};
            }
        }
    }
    BFS();
    printf("%d",ans);
    return 0;
}

void BFS(){
    int currx,curry,dx,dy;
    q.push_back(Origin);
    while(!q.empty()){
        init();
        ans = max(ans, tmp.cnt);
        q.pop_front();
        sharkx = tmp.f[17].x;
        sharky = tmp.f[17].y;
        for(int i=1;i<=16;++i){
            if(tmp.f[i].dir == -1)
                continue;
            currx = tmp.f[i].x;
            curry = tmp.f[i].y;
            for(int j=0;j<=7;++j){
                dx = currx + d[tmp.f[i].dir][0];
                dy = curry + d[tmp.f[i].dir][1];
                if((0<=dx&&dx<4)&&(0<=dy&&dy<4)&&tmp.tmpMap[dx][dy]!=17){//물고기 이동 가능 여부
                    if(tmp.tmpMap[dx][dy]==0){//빈칸 이동
                        tmp.tmpMap[dx][dy] = i;
                        tmp.tmpMap[currx][curry] = 0;
                        tmp.f[i].x = dx;
                        tmp.f[i].y = dy;
                    }
                    else{//다른 물고기와 자리 바꿈
                        swap(tmp.f[tmp.tmpMap[dx][dy]].x,tmp.f[tmp.tmpMap[currx][curry]].x);//다른 물고기와 자리 바꿈
                        swap(tmp.f[tmp.tmpMap[dx][dy]].y,tmp.f[tmp.tmpMap[currx][curry]].y);
                        swap(tmp.tmpMap[currx][curry],tmp.tmpMap[dx][dy]);
                    }
                    break;
                }
                tmp.f[i].dir += 1;
                tmp.f[i].dir%=8;
            }
        }
        tmp.tmpMap[sharkx][sharky] = 0;
        q.push_front(tmp);
        while(true){
            sharkx += d[tmp.f[17].dir][0];
            sharky += d[tmp.f[17].dir][1];
            if(!((0<=sharkx&&sharkx<4)&&(0<=sharky&&sharky<4)))
                break;
            if(tmp.tmpMap[sharkx][sharky]!=0){//상어가 물고기 조우
                /*for(int i=0;i<4;++i){
                    for(int j=0;j<4;++j)
                        printf("%d %d ",tmp.tmpMap[i][j],tmp.f[tmp.tmpMap[i][j]].dir);
                    printf("\n");
                }*/
                tmp.f[17].x = sharkx;
                tmp.f[17].y = sharky;
                tmp.f[17].dir = tmp.f[tmp.tmpMap[sharkx][sharky]].dir;
                tmp.f[tmp.tmpMap[sharkx][sharky]].dir = -1;
                tmp.cnt += tmp.tmpMap[sharkx][sharky];
                tmp.tmpMap[sharkx][sharky] = 17;
                /*for(int i=0;i<4;++i){
                    for(int j=0;j<4;++j)
                        printf("%d %d ",tmp.tmpMap[i][j],tmp.f[tmp.tmpMap[i][j]].dir);
                    printf("\n");
                }
                printf("\n");
                */
                q.push_back(tmp);
                init();
            }
        }
        q.pop_front();
    }
}

void init(){
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j)
            tmp.tmpMap[i][j] = q.front().tmpMap[i][j];
    }
    for(int i=1;i<=17;++i)
        tmp.f[i] = q.front().f[i];
    tmp.cnt = q.front().cnt;
}