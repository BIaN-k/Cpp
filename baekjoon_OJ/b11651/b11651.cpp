#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct point{
    int x,y;
}p;

int n=0;
vector<p> v;

bool sortPoint(p a,p b){
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

int main(){
    scanf("%d",&n);
    for(int i=0,a,b;i<n;++i){
        scanf("%d %d",&a,&b);
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),sortPoint);
    for(int i=0;i<n;++i)
        printf("%d %d\n",v[i].x,v[i].y);
    return 0;
}