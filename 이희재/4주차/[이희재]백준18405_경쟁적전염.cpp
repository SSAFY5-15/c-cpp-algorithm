#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<pair<int, int>> q[1001];
int map[200][200];
int N, K, S, X, Y;
int t;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void init() {
	for (int i = 0; i < 200; i++)
		memset(map[i], 0, sizeof(int) * 200);
	t = 0;
}

bool is_valid(int y, int x) {
	if (y < 0 || y >= N)    return false;
	if (x < 0 || x >= N)    return false;
	return true;
}

bool set_q() {
	bool flag = true;
	for (int i = 1; i <= 1000; i++) {
		int size = q[i].size();
		if (size != 0)    flag = false;

		for (int j = 0; j < size; j++) {
			pair<int, int> p = q[i].front();
			q[i].pop();
			map[p.first][p.second] = i;
			
			for (int k = 0; k < 4; k++) {
				int y = p.first + dy[k];
				int x = p.second + dx[k];
				if (is_valid(y, x)) {
					if (map[y][x] == 0) {
						map[y][x] = -1;
						q[i].push({ y, x });
					}
				}
			}
		}
	}

	return flag;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				q[map[i][j]].push({ i, j });
			}
		}
	cin >> S >> X >> Y;
	X = X - 1; Y = Y - 1;
	set_q();

	while (S != 0) {
		bool flag = set_q();
		if (++t == S || flag)    break;
	}
	
	if (map[Y][X] <= 0)    cout << "0\n";
	else    cout << map[X][Y] << '\n';

	return 0;
}