#include <iostream>
using namespace std;

int N, M;
int map[501][501] = { 0, };
int visited[501][501] = { 0, };
int dp[501][501] = { 0, };

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int solve(int x,int y) {
	if (x == 0 && y == 0) return 1;
	if (!visited[x][y]) {
		visited[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[x][y] < map[nx][ny])
					dp[x][y] += solve(nx, ny);
			}
		}
	}
	return dp[x][y];
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];

	cout << solve(M - 1, N - 1);

	return 0;
}