#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
char map[250][250];
int R, C, sheeps, wolves;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void init() {
	for (int i = 0; i < 250; i++)
		memset(map[i], 0, 250);
	sheeps = 0; wolves = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	init();

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (map[i][j] != '#' && map[i][j] != ',') {
				queue<pair<int, int>> q;
				bool flag = true;
				int s = 0; int w = 0;

				pair<int, int> p = make_pair(i, j);
				q.push(p);
				if (map[i][j] == 'v')    w++;
				else if (map[i][j] == 'k')    s++;
				map[i][j] = ',';
				while (1) {
					pair<int, int> selected = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int y = selected.first + dy[k];
						int x = selected.second + dx[k];
						if (y >= 0 && y < R && x >= 0 && x < C) {
							if (map[y][x] != '#' && map[y][x] != ',') {
								if (map[y][x] == 'v')    w++;
								else if (map[y][x] == 'k')    s++;								
								map[y][x] = ',';
								pair<int, int> tmp_p = make_pair(y, x);
								q.push(tmp_p);
							}
						}
						else    flag = false;
					}
					if (q.empty())    break;
				}
				if (flag) {
					if (s > w)    sheeps += s;
					else    wolves += w;
				}
			}

	cout << sheeps << " " << wolves << '\n';
	return 0;
}