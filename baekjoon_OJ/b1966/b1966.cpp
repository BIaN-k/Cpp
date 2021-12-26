#include <stdio.h>
#include <queue>
#include <deque>
using namespace std;

const int N = 1e2 + 1;

typedef struct Document {
	int index;
	int value;
}D;

int T = 0;
int n, m, cnt = 0;
deque<D> doc;//documents  
priority_queue<int> pq;

void queueClear(priority_queue<int> &oldPq);

int main() {
	scanf("%d", &T);
	for (int k = 0; k < T; ++k) {
		scanf("%d %d", &n, &m);
		for (int i = 0, a; i < n; ++i) {
			scanf("%d", &a);
			doc.push_back({ i,a });
			pq.push(a);
		}
		while (true) {
			if (doc[0].value < pq.top()) {
				doc.push_back(doc[0]);
				doc.pop_front();
			}
			else {//doc[0].value == pq.top()
				++cnt;
				if (doc[0].index == m)
					break;
				doc.pop_front();
				pq.pop();
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		queueClear(pq);
		doc.clear();
	}
	return 0;
}

void queueClear(priority_queue<int> &oldPq) {
	priority_queue<int> NewPq;
	swap(oldPq, NewPq);
	return;
}