#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N, M;
int map[20][20], cp[20][20];
int score;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void init() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = -1;
			cp[i][j] = -1;
		}
	}
	score = 0;
}

void gravity() {
	for (int c = 0; c < N; c++) {
		int base_r = N - 1;
		while (map[base_r][c] != -2) {
			base_r--;
			if (base_r < 0)    break;
		}
		for (int r = base_r - 1; r >= 0; r--) {
			if (map[r][c] > -1 && base_r > r) {
				map[base_r][c] = map[r][c];
				map[r][c] = -2;
				while (map[base_r][c] != -2) {
					base_r--;
					if (base_r < 0)    break;
				}
			}
			if (map[r][c] == -1) {
				base_r = r;
				while (map[base_r][c] != -2) {
					base_r--;
					if (base_r < 0)    break;
				}
			}
			if (base_r < 0)    break;
		}
	}
}

void turn() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cp[r][c] = map[r][c];
		}
	}
	for (int r = 0; r < N; r++) {
		int tmp_r = N - 1 - r;
		for (int c = 0; c < N; c++) {
			map[r][c] = cp[c][tmp_r];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	init();

	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}

	while (1) {
		// pq =>
		// pq of {{# of blocks, # or rainbow blocks}, {row, column}}
		priority_queue<pair<pair<int, int>, pair<int, int>>> pq;

		// copy map to cp
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				cp[r][c] = map[r][c];
			}
		}

		// find block groups in cp[][]
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (cp[r][c] > 0) {
					queue<pair<int, int>> q;
					queue<pair<int, int>> q_rainbows;
					int standard = cp[r][c];
					int cnt_blocks = 1;
					int cnt_rainbows = 0;
					cp[r][c] = -1;
					q.push({ r, c });
					while (!q.empty()) {
						int cur_r = q.front().first;
						int cur_c = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int tmp_r = cur_r + dy[i];
							int tmp_c = cur_c + dx[i];
							if (tmp_r < 0 || tmp_r >= N \
								|| tmp_c < 0 || tmp_c >= N) {
								continue;
							}
							else if (cp[tmp_r][tmp_c] == standard) {
								cp[tmp_r][tmp_c] = -1;
								cnt_blocks++;
								q.push({ tmp_r, tmp_c });
							}
							else if (cp[tmp_r][tmp_c] == 0) {
								cp[tmp_r][tmp_c] = -1;
								cnt_blocks++;
								cnt_rainbows++;
								q_rainbows.push({ tmp_r, tmp_c });
								q.push({ tmp_r, tmp_c });
							}
						}
					}
					pq.push({ { cnt_blocks, cnt_rainbows }, { r,c } });
					while (!q_rainbows.empty()) {
						cp[q_rainbows.front().first][q_rainbows.front().second] = 0;
						q_rainbows.pop();
					}
				}
			}
		}

		if (pq.size() == 0)    break;

		// gain score, blocks set -2
		pair<pair<int, int>, pair<int, int>> biggest_group = pq.top();
		pair<int, int> group_state = pq.top().first;
		if (group_state.first < 2 || group_state.first == group_state.second)    break;
		queue<pair<int, int>> q;
		q.push(biggest_group.second);
		int block_size = group_state.first;
		score += block_size * block_size;
		int standard_color = map[q.front().first][q.front().second];
		map[q.front().first][q.front().second] = -2;
		while (!q.empty()) {
			int cur_r = q.front().first;
			int cur_c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int tmp_r = cur_r + dy[i];
				int tmp_c = cur_c + dx[i];
				if (tmp_r < 0 || tmp_r >= N \
					|| tmp_c < 0 || tmp_c >= N) {
					continue;
				}
				else if (map[tmp_r][tmp_c] == standard_color || map[tmp_r][tmp_c] == 0) {
					map[tmp_r][tmp_c] = -2;
					q.push({ tmp_r, tmp_c });
				}
			}
		}

		gravity();
		turn();
		gravity();
	}
	cout << score << '\n';
	return 0;
}