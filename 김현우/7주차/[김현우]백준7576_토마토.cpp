#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int M, N;
const int dx[2][5] = { {1,0,-1,0},{0,1,0,-1} };
int B[1001][1002];
queue<pair<int, int>>q;
static int date;

bool Wall(int y, int x) {
	if (y >= 1 && y <= N && x >= 1 && x <= M) return 1;
	else return 0;
}

void BFS() {
	pair<int, int> t;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			if (B[t.first + dx[0][k]][t.second + dx[1][k]] == 0 && Wall(t.first + dx[0][k], t.second + dx[1][k])) {
				B[t.first + dx[0][k]][t.second + dx[1][k]] = B[t.first][t.second] + 1;
				if (B[t.first + dx[0][k]][t.second + dx[1][k]] > date) date = B[t.first + dx[0][k]][t.second + dx[1][k]];
				q.push({ t.first + dx[0][k], t.second + dx[1][k] });
			}
		}
	}
}

void check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (B[i][j] == 0) {
				date = -1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> M >> N;
	int tmp = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> B[i][j];
			if (B[i][j] == 1) {
				q.push({ i, j });
			}
			if (B[i][j] == -1) tmp++;
		}
	}
	if (q.size() != M*N - tmp ) { 
		BFS();
		date--;
		check();
	}
	cout << date << endl;

	return 0;
}