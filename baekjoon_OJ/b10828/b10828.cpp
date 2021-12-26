#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
using namespace std;

int n=0,num=0;
char com[20]={0};
stack<int> s;

int main(){
    scanf("%d",&n);
    fgetc(stdin);
    for(int i=0;i<n;++i){
        scanf("%s",com);
        fgetc(stdin);
        if(!strcmp(com,"push")){
            scanf("%d",&num);
            fgetc(stdin);
            s.push(num);
        }
        else if(!strcmp(com,"pop")){
            if(s.size()==0)
                printf("-1\n");
            else{
                printf("%d\n",s.top());
                s.pop();
            }
        }
        else if(!strcmp(com,"size")){
            printf("%d\n",s.size());
        }
        else if(!strcmp(com,"empty")){
            printf("%d\n",s.empty());
        }
        else{
            if(!s.size())
                printf("-1\n");
            else
                printf("%d\n",s.top());
        }
    }
    return 0;
}