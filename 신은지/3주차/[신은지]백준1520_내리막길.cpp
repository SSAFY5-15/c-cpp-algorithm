#include <iostream>
#include <cstring>

using namespace std;

int m, n;
int mapp[501][501] = { 0, };
int dp[501][501] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int dfs(int y, int x) {
	if (y == m - 1 && x == n - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy < 0 || yy >= m || xx < 0 || xx >= n) continue;
		if (mapp[yy][xx] < mapp[y][x]) {
			dp[y][x] += dfs(yy, xx);
		}
	}
	return dp[y][x];
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mapp[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
}