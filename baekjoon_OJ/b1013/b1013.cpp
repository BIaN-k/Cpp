#include <stdio.h>
#include <string>
#include <iostream>
#define pr_of if(index>=elec.size())return; //prevent_overflow
using namespace std;

bool com = false;
int T=0;
string elec;

void check(int index);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(NULL);
    scanf("%d",&T);
    for(int k=0;k<T;++k){
        com = false;
        cin >> elec;
        check(0);
        elec.clear();
        if(com == true)
            printf("YES\n");//cout << "YES\n";
        else
            printf("NO\n");//cout << "NO\n";
    }
    return 0;
}

void check(int index){
    //cout << index << " ";
    if(index == elec.size()){
        com = true;
        return;
    }
    else if(index > elec.size()){
        return;
    }
    if(com == true)
        return;
    if(elec[index] == '0'){// 0 1
        if(index+1>=elec.size())
            return;
        //cout << "first st ";
        ++index;
        pr_of;
        if(elec[index] == '1')
            ++index;
        else
            return;
        //cout << "first ";
        check(index);
    }
    else{//elec[i] == 1 -> 1 0 0 + 1 +
        if(index+3>=elec.size())
            return;
        //cout << "second st ";
        ++index;
        if(elec[index] == '0' && elec[index+1] == '0'){
            index+=2;
            while(elec[index] == '0'){
                ++index;
                pr_of
            }
            if(elec[index] == '1'){
                ++index;
                if(index >= elec.size())
                    check(index);
                else if(elec[index] == '0')
                    check(index);
                else{//elec[index] == '1'
                    while(elec[index] == '1' && index < elec.size())
                        ++index;
                    check(index);
                    check(index-1);
                }
            }
            else
                return;
        }
        else
            return;
        //cout << "second ";
    }
}//0110000111111000100000010100011101110011111101111000011110111010001001100111101101000101011110100100
//100111100