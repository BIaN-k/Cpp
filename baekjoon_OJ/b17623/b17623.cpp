#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 1e3 + 2;

typedef struct _bracket{
    string dmap, str;
} br;

br DP[N*2];
int T, n;
br tmp;

bool cmp(string a,string b){
    if(a.length()!=b.length())
        return a.length()<b.length();
    else
        return a<b;
}

void init();

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(NULL);
    cin >> T;
    init();
    for (int i = 1; i <= N; ++i){
        //cout << i << " " << DP[i].str << "\n";
        for (int j = 1; j <= i; ++j){
            if (i + j > N)
                break;
            tmp.dmap = min(DP[i].dmap,DP[j].dmap) + max(DP[i].dmap,DP[j].dmap);
            if (cmp(tmp.dmap, DP[i + j].dmap)){
                DP[i + j].dmap = tmp.dmap;
                if (DP[i].dmap < DP[j].dmap)
                    DP[i + j].str = DP[i].str + DP[j].str;
                else
                    DP[i + j].str = DP[j].str + DP[i].str;
            }
        }
        tmp.dmap = "1" + DP[i].dmap + "2";
        if (i * 2 <= N && cmp(tmp.dmap, DP[i * 2].dmap)){
            DP[i * 2].dmap = tmp.dmap;
            DP[i * 2].str = "(" + DP[i].str + ")";
        }
        tmp.dmap = "3" + DP[i].dmap + "4";
        if (i * 3 <= N && cmp(tmp.dmap, DP[i * 3].dmap)){
            DP[i * 3].dmap = tmp.dmap;
            DP[i * 3].str = "{" + DP[i].str + "}";
        }
        tmp.dmap = "5" + DP[i].dmap + "6";
        if (i * 5 <= N && cmp(tmp.dmap, DP[i * 5].dmap)){
            DP[i * 5].dmap = tmp.dmap;
            DP[i * 5].str = "[" + DP[i].str + "]";
        }
    }
    for(int i=0;i<T;++i){
        cin >> n;
        cout << DP[n].str << "\n";
    }
    return 0;
}

void init(){
    for(int i=1;i<N;++i){
        DP[i].dmap = "9999999999999999999";
        DP[i].str.clear();
    }
    DP[1].dmap = "12";
    DP[2].dmap = "34";
    DP[3].dmap = "56";
    DP[1].str = "()";
    DP[2].str = "{}";
    DP[3].str = "[]";
}