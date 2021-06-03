#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
char puyo[12][6];
char reserve;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

bool is_valid(int r, int c) {
	if (r < 0 || r > 11)    return false;
	if (c < 0 || c > 5)    return false;
	if (puyo[r][c] != reserve)    return false;
	return true;
}

void dfs(int r, int c) {
	q.push({ r,c });
	puyo[r][c] = '.';
	for (int i = 0; i < 4; i++) {
		int new_r = r + dr[i];
		int new_c = c + dc[i];
		if (is_valid(new_r, new_c))    dfs(new_r, new_c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int cnt = 0;

	for (int r = 11; r >= 0; r--)
		for (int c = 0; c < 6; c++)
			cin >> puyo[r][c];

	while (1) {
		bool flag = true;
		
		for (int r = 0; r < 12; r++)
			for (int c = 0; c < 6; c++) {
				if (puyo[r][c] != '.') {
					reserve = puyo[r][c];
					dfs(r, c);
					int size = q.size();
					if (size < 4) {
						while (!q.empty()) {
							puyo[q.front().first][q.front().second] = reserve;
							q.pop();
						}
					}
					else {
						flag = false;
						while (!q.empty())    q.pop();
					}
				}
			}

		if (flag)    break;
		cnt++;
		for (int c = 0; c < 6; c++) {
			int base = 0;
			int tmp;
			while (1) {
				if (puyo[base][c] != '.')    base++;
				else    break;
				if (base == 12)    break;
			}
			for (int r = base + 1; r < 12; r++) {
				if (puyo[r][c] == '.')    continue;
				puyo[base][c] = puyo[r][c];
				puyo[r][c] = '.';
				base++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}