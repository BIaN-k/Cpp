#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Person {
    int index;
    string name;
} p;

int n, m;
vector<p> heard, saw;
vector<string> heardSaw;
string tmp;

bool personSort(p a, p b) {
    return a.name < b.name;
}

bool bn_search(string str);

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        heard.push_back({i, tmp});
    }
    for (int i = 1; i <= m; ++i) {
        cin >> tmp;
        saw.push_back({i, tmp});
    }
    sort(heard.begin(), heard.end(), personSort);
    sort(saw.begin(), saw.end(), personSort);
    for (int i = 0; i < m; ++i) {
        if (bn_search(saw[i].name))
            heardSaw.push_back(saw[i].name);
    }
    cout << heardSaw.size() << '\n';
    for (int i = 0; i < heardSaw.size(); ++i)
        cout << heardSaw[i] << '\n';
    return 0;
}

bool bn_search(string str) {
    int l = 0, r = n - 1, md = 0;
    while (l < r) {
        md = (l + r) / 2;
        if (str < heard[md].name)
            r = md - 1;
        else if (str == heard[md].name)
            return true;
        else
            l = md + 1;
    }
    if (l == r) {
        if (str == heard[l].name)
            return true;
    }
    return false;
}