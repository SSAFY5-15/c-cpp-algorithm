#include <iostream>
#include <cstring>
#include <queue>
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;

int wall[50][50];
int room[50][50], room_size[2500];
int max_size, twin_size, room_num, m, n;
// bit 0 서
// bit 1 북
// bit 2 동
// bit 3 남
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void init() {
	for (int i = 0; i < 50; i++) {
		memset(wall[i], 0, sizeof(int) * 50);
		memset(room[i], -1, sizeof(int) * 50);
	}
	memset(room_size, 0, sizeof(int) * 2500);
	max_size = 0;
	room_num = 0;
	twin_size = 0;
}

bool is_valid(int y, int x) {
	if (y < 0 || y >= n)    return false;
	if (x < 0 || x >= m)    return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	init();
	cin >> m >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> wall[y][x];
	
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if (room[y][x] == -1) {
				queue<pair<int, int>> q;
				int count = 0;
				room[y][x] = room_num;
				q.push({y, x});
				while (!q.empty()) {
					pair<int, int> cur;
					cur = q.front();
					q.pop();
					count++;
					for (int i = 0; i < 4; i++) {
						if (!(wall[cur.first][cur.second] & (1 << i))) {
							int new_y = cur.first + dy[i];
							int new_x = cur.second + dx[i];
							if (room[new_y][new_x] == -1) {
								room[new_y][new_x] = room_num;
								q.push({ new_y, new_x });
							}
						}
					}
				}
				room_size[room_num] = count;
				room_num++;
			}
		}

	// 방의 수
	cout << room_num << '\n';

	// 가장 큰 방의 크기
	for (int i = 0; i < room_num; i++)
		if (room_size[i] > max_size)    max_size = room_size[i];
	cout << max_size << '\n';

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			int s = room_size[room[y][x]];
			for (int i = 0; i < 4; i++) {
				int new_y = y + dy[i];
				int new_x = x + dx[i];
				if (is_valid(new_y, new_x)) {
					if (room[y][x] != room[new_y][new_x]) {
						int new_s = room_size[room[new_y][new_x]];
						twin_size = MAX(twin_size, s + new_s);
					}
				}
			}
		}
	}
	cout << twin_size << '\n';

	return 0;
}