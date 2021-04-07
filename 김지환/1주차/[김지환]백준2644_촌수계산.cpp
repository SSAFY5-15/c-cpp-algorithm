#include <iostream>
using namespace std;
int N, a, b;
int adj[100][100] = { 0, };
int DFS(int n) {
	if (n == b) return 0;
	int i, j, ret, mn=1e9;
	for (i = 1; i <= N; i++) {
		if (adj[n][i]) {
			adj[i][n] = 0;
			ret = DFS(i)+1;
			if (ret < mn) mn = ret;
			adj[i][n] = 1;
		}
	}
	return mn;
}

int main() {
	int tmp1, tmp2, tmp3, ret =0;
	cin >> N >> a >> b;
	cin >> tmp1;
	while (tmp1--) {
		cin >> tmp2 >> tmp3;
		adj[tmp2][tmp3] = 1;
		adj[tmp3][tmp2] = 1;
	}
	ret = DFS(a);
	if (ret == 1e9) cout << -1 << endl;
	else cout << ret << endl;
}