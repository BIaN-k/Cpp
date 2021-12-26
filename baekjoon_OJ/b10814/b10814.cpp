#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;

typedef struct person{
    int age;
    char name[101];
    int index;
} p;

p people[N];
int n = 0;

bool sortP(p a, p b){
    if (a.age == b.age)
        return a.index < b.index;
    return a.age < b.age;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d %s", &people[i].age, &people[i].name);
        people[i].index = i;
    }
    sort(people, people + n, sortP);
    for (int i = 0; i < n; ++i)
        printf("%d %s\n", people[i].age, people[i].name);
    return 0;
}