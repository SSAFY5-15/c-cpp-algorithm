#include <iostream>

using namespace std;
int R, C;
char B[253][253];
int v, k;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void dfs(int y, int x, int* tv, int* tk) {
	if (B[y][x] == 'v') (*tv)++;
	if (B[y][x] == 'k') (*tk)++;
	B[y][x] = '#';
	for (int i = 0; i < 4; i++) {
		if (y + dy[i] >= 0 && y + dy[i] < R && x + dx[i] >= 0 && x + dx[i] < C) {
			if (B[y + dy[i]][x + dx[i]] != '#') {
				dfs(y + dy[i], x + dx[i], tv, tk);
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> B[i];
	}
	int t1 = 0;
	int t2 = 0;
	int* tv = &t1;
	int* tk = &t2;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			*tv = 0;
			*tk = 0;

			if (B[i][j] != '#') dfs(i, j, tv, tk);

			if ((*tv) >= (*tk)) (*tk) = 0;
			else (*tv) = 0;

			v += *tv;
			k += *tk;
		}
	}
	cout << k <<" " << v << endl;
	return 0;
}