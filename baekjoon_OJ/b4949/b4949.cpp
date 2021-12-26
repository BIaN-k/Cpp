#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int N = 1e2 + 1;

string arr;
int s=0,l=0;
bool balance = true;
stack<char> last;

void swap(stack<char> *s);

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(NULL);
    while(true){
        balance = true;
        getline(cin,arr);
        //cout << arr << "\n";
        if(arr[0] == '.')
            break;
        for(int i=0;i<arr.length();++i){
            printf("%d %c %c\n",i,arr[i],last.top());
            if(arr[i] == '('){
                last.push('(');
                ++s;
            }
            else if(arr[i] == ')'){
                if(s == 0 || last.empty()){
                    balance = false;
                    break;
                }
                else if(!last.empty()){
                    if(last.top() != '('){
                        balance = false;
                        break;
                    }
                }
                else{
                    last.pop();
                    --s;
                }
            }
            else if(arr[i] == '['){
                last.push('[');
                ++l;
            }
            else if(arr[i] == ']'){
                if(l == 0 || last.empty()){
                    balance = false;
                    break;
                }
                else if(!last.empty()){
                    if(last.top() != '['){
                        balance = false;
                        break;
                    }
                }
                else{
                    last.pop();
                    --l;
                }
            }
        }
        if(s == true || l == true)
            balance = false;
        if(balance == true)
            cout << "yes\n";
        else
            cout << "no\n";
        s = false;
        l = false;
        swap(&last);
        arr.clear();
    }
    return 0;
}

void swap(stack<char> *s){
    stack<char> newStack;
    swap(newStack,*s);
}