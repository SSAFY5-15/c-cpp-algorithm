#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

unsigned int cave[125][125], lost[125][125];
int N;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void init() {
	for (int i = 0; i < 125; i++) {
		memset(cave[i], 0, sizeof(unsigned int) * 125);
		memset(lost[i], 255, sizeof(unsigned int) * 125);
	}
}

bool is_valid(int y, int x) {
	if (y < 0 || y >= N)    return false;
	if (x < 0 || x >= N)    return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc = 0;

	while (1) {
		init();
		tc++;

		cin >> N;
		if (N == 0)    break;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> cave[y][x];
		
		lost[0][0] = cave[0][0];
		queue<pair<int, int>> q;
		q.push({0, 0});
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int y = cur.first + dy[i];
				int x = cur.second + dx[i];
				if (is_valid(y, x)) {
					if (lost[y][x] > lost[cur.first][cur.second] + cave[y][x]) {
						lost[y][x] = lost[cur.first][cur.second] + cave[y][x];
						q.push({ y, x });
					}
				}
			}
		}
		cout << "Problem " << tc << ": " << lost[N-1][N-1] << '\n';
	}

	return 0;
}