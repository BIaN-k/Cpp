#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct point{
    int x,y;
}p;

int n=0;
vector<p> po;

bool sortP(p a,p b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main(){
    scanf("%d",&n);
    for(int i=0,a,b;i<n;++i){
        scanf("%d %d",&a,&b);
        po.push_back({a,b});
    }
    sort(po.begin(),po.end(),sortP);
    for(int i=0;i<n;++i)
        printf("%d %d\n",po[i].x,po[i].y);
    return 0;
}