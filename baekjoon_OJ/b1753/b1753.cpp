#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int N = (1e4+1)*3;

typedef struct _Line{
    int dest;
    int w;
}L;

bool v[N]={0};
vector<L> line[N];
int dist[N]={0};
int V,E,K;
priority_queue<L> pq;

bool operator<(L a,L b){
    return a.w>b.w;
}

void dijkstra(int start);

int main(){
    fill(dist,dist+N-1,INT_MAX-100);
    scanf("%d %d %d",&V,&E,&K);
    for(int i=0,a,b,c;i<E;++i){
        scanf("%d %d %d",&a,&b,&c);
        line[a].push_back({b,c});
    }
    dijkstra(K);
    for(int i=1;i<=V;++i){
        if(dist[i]==INT_MAX-100)
            printf("INF\n");
        else
            printf("%d\n",dist[i]);
    }
    return 0;
}

void dijkstra(int start){
    dist[start] = 0;
    int now = start,des;
    while(true){
        while(v[now]){
            if(pq.empty())
                return;
            now = pq.top().dest;//현 노드
            pq.pop();
        } 
        /*printf("%d\n",now);
        for(int i=1;i<=V;++i)
            printf("%d ",dist[i]);
        printf("\n");*/
        v[now] = true;
        for(int i=0;i<line[now].size();++i){
            des = line[now][i].dest;//비교할 주위 노드
            if(dist[des]>dist[now]+line[now][i].w){//최단거리 비교
                dist[des] = dist[now] + line[now][i].w;
                pq.push({des,dist[des]});
            }
        }
    }
}