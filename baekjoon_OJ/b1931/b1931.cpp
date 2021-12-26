#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

typedef struct Meetings {
    int st, fin;
} meet;

vector<meet> aMeets, cMeets;  //all meetings, choiced meetings
int n = 0, ans = 1;
meet tmp;

bool meetSort(meet a, meet b) {
    if (a.st == b.st)
        return a.fin < b.fin;
    return a.st < b.st;
}

int main() {
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        aMeets.push_back({a, b});
    }
    sort(aMeets.begin(), aMeets.end(), meetSort);
    tmp = aMeets[0];
    cMeets.push_back(tmp);
    for (int i = 1; i < n; ++i) {
        if (tmp.st == tmp.fin) {
            tmp = aMeets[i];
            cMeets.push_back(tmp);
        } else if (tmp.st != aMeets[i].st) {
            if (tmp.fin < aMeets[i].fin) {
                tmp = aMeets[i];
                cMeets.push_back(tmp);
            } else {
                if (aMeets[i].st == aMeets[i].fin && aMeets[i].st == tmp.fin) {
                    tmp = aMeets[i];
                    cMeets.push_back(tmp);
                } else {
                    tmp = aMeets[i];
                    while (!cMeets.empty() && tmp.fin < cMeets.back().fin)
                        cMeets.pop_back();
                    cMeets.push_back(tmp);
                }
            }
        }
    }
    tmp = cMeets[0];
    for (int i = 1; i < cMeets.size(); ++i) {
        if (tmp.fin <= cMeets[i].st) {
            ++ans;
            tmp = cMeets[i];
        }
    }
    printf("%d", ans);
    return 0;
}