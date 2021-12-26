#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = (1e5 + 1) * 5;

typedef struct M{
    int index;
    int value;
}Mode;

bool ModeSort(Mode a,Mode b){
    if(a.value == b.value)
        return a.index>b.index;
    return a.value<b.value;
}

vector<int> arr;
Mode num[8000 + 1];//각각의 수가 나온 회수 (-4000 ~ 4000)
int n=0;
double average;
int mode = 0;

int main(){
    scanf("%d",&n);
    for(int i=-4000;i<=4000;++i)
        num[i+4000].index = i;
    for(int i=0,a;i<n;++i){
        scanf("%d",&a);
        arr.push_back(a);
        average += a;
        ++num[arr[i]+4000].value;
    }
    average /= (double)n;
    sort(arr.begin(),arr.end());
    sort(num,num+8001,ModeSort);
    if(num[8000].value == num[8000 - 1].value)
        mode = num[8000 - 1].index;
    else
        mode = num[8000].index;
    printf("%.0lf\n%d\n%d\n%d",floor(average+0.5),arr[n/2],mode,arr.back()-arr.front());
    return 0;
}