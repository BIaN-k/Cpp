#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

const int N=(1e3+1)*5;

vector<int> line[N];//간선
vector<int> black;//검은 돌
queue<int> q;//BFS용 큐
int maxTree[N]={0};//쿼리 (i,j)에서 j일때 최대 정점
int tmpTree[N]={0};//BFS용 임시 maxTree
bool visit[N]={0};//BFS용 방문 배열
int n,b,Q,u,v;



int main(){
    scanf("%d %d",&n,&b);
    for(int i=0,a;i<b;++i){
        scanf("%d",&a);
        black.push_back(a);
    }
    for(int i=1,a,b;i<n;++i){
        scanf("%d %d",&a,&b);
        line[a].push_back(b);
        line[b].push_back(a);
    }
    scanf("%d",&Q);
    
    for(int i=0;i<Q;++i)
    return 0;
}