#include <iostream>
#include <stdlib.h>
using namespace std;

int n, res;
int selected[21] = {0,};
int stats[21][21] = {0,};

int calc(int sel1[], int sel2[]) {
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = i+1; j < n / 2; j++) {
			sum1 += stats[sel1[i]][sel1[j]] + stats[sel1[j]][sel1[i]];
			sum2 += stats[sel2[i]][sel2[j]] + stats[sel2[j]][sel2[i]];
		}
	}
	return abs(sum1 - sum2);
}

void dfs(int idx, int cnt) {
	if (cnt == n/2) {
		int sel1[10];
		int sel2[10];
		int idx1 = 0, idx2 = 0;
		for (int i = 1; i < n + 1; i++) {
			if (selected[i]) sel1[idx1++] = i;
			else sel2[idx2++] = i;
		}
		int ans = calc(sel1, sel2);
		if (res > ans) res = ans;
		return;
	}
	
	for (int i = idx; i < n+1; i++) {
		if (n + 1 - i >= n / 2 - cnt) {
			selected[i] = 1;
			dfs(i + 1, cnt + 1);
			selected[i] = 0;
		}
		else break;
	}

}

int main() {
    ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n+1; j++) {
			cin >> stats[i][j];
		}
	}
	res = 20 * 100;
	dfs(1, 0);
	cout << res;
}