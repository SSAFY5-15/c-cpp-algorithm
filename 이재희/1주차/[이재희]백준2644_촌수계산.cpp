#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 110;
int n,m;
int a, b;
vector<int> v[MAX];
int p[MAX];
int main() {
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int tempa, tempb;
		scanf("%d %d", &tempa, &tempb);
		v[tempa].push_back(tempb);
		p[tempb] = tempa;
	}

	int now = a;
	vector<int> candi;
	while (true) {
		candi.push_back(now);
		now = p[now];

		if (now == 0) break;
	}

	now = b;
	vector<int> candi2;
	while (true) {
		candi2.push_back(now);
		now = p[now];

		if (now == 0) break;
	}

	int x = candi.size();
	int y = candi2.size();
	int ans = -1;
	for (int i = 0; i < x; i++) {
		if (ans != -1) break;
		for (int j = 0; j < y; j++) {
			if (candi[i] == candi2[j]) {
				ans = i + j;
				break;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}