#include <iostream>
#include <string>
#include <regex>
using namespace std;

int T=0;
string elec;

int main(){
    cin >> T;
    regex comp("((100+1+)|(01))+");
    for(int i=0;i<T;++i){
        cin >> elec;
        bool match = regex_match(elec,comp);
        if(match)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}