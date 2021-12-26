#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

const int N = 1e1 + 1;

typedef struct _Line{
    int dest;
    int w;
}L;

int n, m, c=0;
int mapp[N][N] = {0},mLine[N][N] = {0};
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool vis[N][N] = {0}, v[N] = {0};
vector<L> line[N];
priority_queue<L> pq;

bool operator<(L a,L b){
    return a.w>b.w;
}

void DFS(int x,int y,int cnt);//섬 노드화

void vLining();//수직으로 섬 사이 간선 이음

void hLining();//수평으로 섬 사이 간선 이음

void pushLine();//벡터에 간선 추가

int prim();

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            scanf("%d",&mapp[i][j]);
    }
    for(int i=0;i<7;++i)
        fill(mLine[i],mLine[i]+7,INT_MAX-1);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mapp[i][j]&&!vis[i][j])
                DFS(i,j,++c);
        }
    }
    vLining();
    hLining();
    /*for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            printf("%d ",mapp[i][j]);
        printf("\n");
    }*/
    pushLine();
    printf("%d",prim());
    return 0;
}

void DFS(int x,int y,int cnt){
    int dx,dy;
    vis[x][y] = true;
    mapp[x][y] = cnt;
    for(int i=0;i<4;++i){
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if((0<=dx&&dx<n)&&(0<=dy&&dy<m)&&!vis[dx][dy]&&mapp[dx][dy])
            DFS(dx,dy,cnt);
    }
}

void vLining(){
    int curr, Ycurr;
    for(int j=0;j<m;++j){
        curr = -1;
        Ycurr = 0;
        for(int i=0;i<n;++i){
            if(mapp[i][j] != curr&&mapp[i][j]){
                //printf("%d %d %d\n",i,j,curr);
                if(i-Ycurr>=3)
                    mLine[curr][mapp[i][j]] = min(mLine[curr][mapp[i][j]],i-Ycurr-1);
                curr = mapp[i][j];
            }
            while(curr == mapp[i][j]){
                Ycurr = i;
                ++i;
            }
        }
    }
    return;
}

void hLining(){
    int curr, Xcurr;
    for(int i=0;i<n;++i){
        curr = -1;
        Xcurr = 0;
        for(int j=0;j<m;++j){
            if(mapp[i][j] != curr&&mapp[i][j]){
                if(j-Xcurr>=3)
                    mLine[curr][mapp[i][j]] = min(mLine[curr][mapp[i][j]],j-Xcurr-1);
                curr = mapp[i][j];
            }
            while(curr == mapp[i][j]){
                Xcurr = j;
                ++j;
            }
        }
    }
    return;
}

void pushLine(){
    for(int i=0;i<=c;++i){
        for(int j=0;j<=c;++j){
            if(mLine[i][j]!=INT_MAX-1){
                //printf("%d %d %d\n",i,j,mLine[i][j]);
                line[i].push_back({j,mLine[i][j]});
                line[j].push_back({i,mLine[i][j]});
            }
        }
    }
}

int prim(){
    int ans=0;
    L tmp;
    v[1] = true;
    for(int i=0;i<line[1].size();++i)
        pq.push(line[1][i]);
    while(!pq.empty()){
        tmp.dest = pq.top().dest;
        tmp.w = pq.top().w;
        //printf("%d %d\n",tmp.dest,tmp.w);
        v[tmp.dest] = true;
        ans += tmp.w;
        while(!pq.empty()&&v[pq.top().dest])
            pq.pop();
        //printf("%d %d\n",pq.top().dest,pq.top().w);
        for(int i=0;i<line[tmp.dest].size();++i){
            //printf("%d\n",line[tmp.dest][i].dest);
            if(!v[line[tmp.dest][i].dest])
                pq.push(line[tmp.dest][i]);
        }
    }
    for(int i=1;i<=c;++i){
        if(!v[i])
            return -1;
    }
    return ans;
}