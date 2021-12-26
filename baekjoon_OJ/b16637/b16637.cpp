#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e2 + 1;

char math[N]={0};//수식
int calc[N]={0};//calc[n] = n과 n+2번째 숫자를 괄호로 계산
int n=0;
long long int ans = (-1)*1e12;

void br(int start,long long int value);

int main(){
    scanf("%d\n%s",&n,math);
    for(int i=0;i<n;++i){
        if('0'<=math[i]&&math[i]<='9'){
            if(math[i+1]=='+')
                calc[i] = (math[i] - '0') + (math[i+2] - '0');
            else if(math[i+1]=='-')
                calc[i] = (math[i] - '0') - (math[i+2] - '0');
            else if(math[i+1]=='*')
                calc[i] = (math[i] - '0') * (math[i+2] - '0');
        }
    }
    br(0,math[0] - '0');
    printf("%d",ans);
    return 0;
}

void br(int start,long long int value){
    if(start == n-1){
        ans = max(ans, value);
        return;
    }
    if(math[start+1]=='+'){
        br(start + 2, value + (math[start + 2] - '0'));
        br(start + 4, value + calc[start + 2]);
    }
    else if(math[start+1]=='-'){
        br(start + 2, value - (math[start + 2] - '0'));
        br(start + 4, value - calc[start + 2]);
    }
    else if(math[start+1]=='*'){
        br(start + 2, value * (math[start + 2] - '0'));
        br(start + 4, value * calc[start + 2]);
    }
}

/*
DP 실패

#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e2 + 1;

char math[N]={0};//수식
long long int DP[N]={0},DP2[N]={0};//DP[i] = i번째 수까지의 연산의 최댓값
int calc[N]={0};//calc[n] = n과 n+2번째 숫자를 괄호로 계산
int n=0;

int main(){
    fill(DP,DP+N-1,(-1)*1e12);
    fill(DP2,DP2+N-1,1e12);
    scanf("%d\n%s",&n,math);
    for(int i=0;i<n;++i){
        if('0'<=math[i]&&math[i]<='9'){
            if(math[i+1]=='+')
                calc[i] = (math[i] - '0') + (math[i+2] - '0');
            else if(math[i+1]=='-')
                calc[i] = (math[i] - '0') - (math[i+2] - '0');
            else if(math[i+1]=='*')
                calc[i] = (math[i] - '0') * (math[i+2] - '0');
        }
    }
    DP[0] = math[0] - '0';
    DP2[0] = math[0] - '0';
    for(int i=0;i<n;++i){
        if('0'<=math[i]&&math[i]<='9'){
            if(math[i+1]=='+'){
                DP[i+2] = max(DP[i+2], DP[i] + (math[i+2] - '0'));
                DP[i+4] = max(DP[i+4], DP[i] + calc[i+2]);
                DP2[i+2] = min(DP2[i+2], DP2[i] + (math[i+2] - '0'));
                DP2[i+4] = min(DP2[i+4], DP2[i] + calc[i+2]);

            }
            else if(math[i+1]=='-'){
                DP[i+2] = max(DP[i+2], DP[i] - (math[i+2] - '0'));
                DP[i+4] = max(DP[i+4], DP[i] - calc[i+2]);
                DP2[i+2] = min(DP2[i+2], DP2[i] - (math[i+2] - '0'));
                DP2[i+4] = min(DP2[i+4], DP2[i] - calc[i+2]);
            }
            else if(math[i+1]=='*'){
                DP[i+2] = max(DP[i+2], max(DP[i] * (math[i+2] - '0'), DP2[i] * (math[i+2] - '0')));
                DP[i+4] = max(DP[i+4], max(DP[i] * calc[i+2], DP2[i] * calc[i+2]));
                DP2[i+2] = min(DP2[i+2], min(DP[i] * (math[i+2] - '0'), DP2[i] * (math[i+2] - '0')));
                DP2[i+4] = min(DP2[i+4], max(DP[i] * calc[i+2], DP2[i] * calc[i+2]));
            }
        }
    }
    for(int i=0;i<n;++i)
        printf("%d ",DP[i]);
    printf("\n");
    for(int i=0;i<n;++i)
        printf("%d ",DP2[i]);
    printf("\n%d",DP[n-1]);
    return 0;
}
*/