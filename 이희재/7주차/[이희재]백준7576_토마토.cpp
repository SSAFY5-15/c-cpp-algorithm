#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
int box[1000][1000];
int N, M, day, tomatos;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void init() {
	day = 0;
	tomatos = 0;
}

bool is_valid(int r, int c) {
	if (r < 0 || r >= M)    return false;
	if (c < 0 || c >= N)    return false;
	if (box[r][c] == -1)    return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	cin.tie(NULL);
	init();

	for (int r = 0; r < M; r++)
		for (int c = 0; c < N; c++) {
			cin >> box[r][c];
			if (box[r][c] == 1)    q.push({ r, c });
			else if (box[r][c] == 0)    tomatos++;
		}

	if (tomatos == 0) {
		cout << "0\n";
		return 0;
	}
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			pair<int, int> base;
			base = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int r = base.first + dy[j];
				int c = base.second + dx[j];
				if (is_valid(r, c)) {
					if (box[r][c] == 0) {
						box[r][c] = 1;
						tomatos--;
						q.push({ r, c });
					}
				}
			}
		}
		day++;
	}

	if (tomatos != 0)    cout << "-1\n";
	else    cout << day - 1 << '\n';

	return 0;
}