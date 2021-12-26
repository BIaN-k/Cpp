#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 20 + 1;

typedef struct _fish{
    int x,y;
    int dist;
}fish;

typedef struct _Shark{
    int x,y;
    int size;
    int eaten;
}_shark;

_shark shark;
int n=0,fishCnt=0,time=0;
int mapp[N][N]={0};
bool v[N][N]={0};
queue<fish> q;
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool ch = false;
vector<fish> mov,tmp;

bool movSort(fish a,fish b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

void init();

void BFS();

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&mapp[i][j]);
            if(mapp[i][j]==9){
                shark.x = i;
                shark.y = j;
            }
            if(mapp[i][j])
                ++fishCnt;
        }
    }
    shark.size = 2;
    shark.eaten = 0;
    --fishCnt;//상어 제외
    for(int i=0;i<fishCnt;++i){
        init();
        BFS();
        if(ch == true)
            break;
    }
    printf("%d",time);
    return 0;
}

void init(){
    for(int i=0;i<N;++i)
        fill(v[i],v[i]+N,false);
    queue<fish> newQueue;
    swap(q,newQueue);
    //printf("%d\n",time);
    mapp[shark.x][shark.y] = 9;
    /*for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            printf("%d ",mapp[i][j]);
        printf("\n");
    }*/
}

void BFS(){
    int dx,dy;
    fish tmp;
    mapp[shark.x][shark.y]=0;
    v[shark.x][shark.y]=true;
    q.push({shark.x,shark.y,0});
    while(!q.empty()){
        tmp.x = q.front().x;
        tmp.y = q.front().y;
        tmp.dist = q.front().dist;
        if(!mov.empty()){
            if(tmp.dist>mov[0].dist){
                sort(mov.begin(),mov.end(),movSort);
                //printf("%d %d %d %d\n",mov[0].x,mov[0].y,mov[0].dist,shark.size);
                mapp[mov[0].x][mov[0].y] = 0;
                ++shark.eaten;
                if(shark.eaten==shark.size){
                    ++shark.size;
                    shark.eaten = 0;
                }
                time += mov[0].dist;
                shark.x = mov[0].x;
                shark.y = mov[0].y;
                mov.clear();
                return;
            }
        }
        //printf("%d %d %d\n",tmp.x,tmp.y,tmp.dist);
        q.pop();
        for(int i=0;i<4;++i){
            dx = tmp.x + dir[i][0];
            dy = tmp.y + dir[i][1];
            //printf("%d %d %d %d\n",dx,dy,v[dx][dy],mapp[dx][dy]);
            if((0<=dx&&dx<n)&&(0<=dy&&dy<n)&&!v[dx][dy]&&mapp[dx][dy]<=shark.size){
                if(mapp[dx][dy]<shark.size&&mapp[dx][dy]&&(mov.empty()||mov[0].dist==tmp.dist+1))
                    mov.push_back({dx,dy,tmp.dist+1});
                v[dx][dy] = true;
                q.push({dx,dy,tmp.dist+1});
            }
        }
    }
    if(!mov.empty()){
        sort(mov.begin(),mov.end(),movSort);
        //printf("%d %d %d %d\n",mov[0].x,mov[0].y,mov[0].dist,shark.size);
        mapp[mov[0].x][mov[0].y] = 0;
        ++shark.eaten;
        if(shark.eaten==shark.size){
            ++shark.size;
            shark.eaten = 0;
        }
        time += mov[0].dist;
        shark.x = mov[0].x;
        shark.y = mov[0].y;
        mov.clear();
        return;
    }
    ch = true;
}