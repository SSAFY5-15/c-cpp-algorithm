#include <iostream>
#include <cstring>
using namespace std;

int score[6][3], in[4][6][3];
int check[4];
bool t[4];

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			score[i][j] = 0;
		}
	}
	memset(t, true, sizeof(bool) * 4);
	memset(check, 0, sizeof(int) * 4);
}

void dfs(int N, int M, bool c[4]) {
	if (N == 5) {
		for (int i = 0; i < 4; i++)
			if (c[i] == true) {
				bool f = true;
				for (int k = 0; k < 3; k++) {
					if (score[N][k] != in[i][N][k]) {
						f = false;
						break;
					}
				}
				if (f)    check[i] = 1;
			}
	}
	else {
		for (int i = 0; i < 3; i++) {
			score[N][i]++;
			score[M][2 - i]++;
			if (M != 5)    dfs(N, M+1, c);
			else {
				bool flag = false;
				bool t_c[4] = { false, };

				for (int j = 0; j < 4; j++) {
					if (c[j] == true) {
						bool f = true;
						for (int k = 0; k < 3 ; k++){
							if (score[N][k] != in[j][N][k]) {
								f = false;
								break;
							}
						}
						t_c[j] = f;
					}
				}
				for (int j = 0; j < 4; j++) {
					if (c[j] == true)    flag = true;
				}
				if (flag)    dfs(N + 1, N + 2, t_c);
			}
			score[M][2 - i]--;
			score[N][i]--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 3; k++)
				cin >> in[i][j][k];

	dfs(0, 1, t);

	for (int i = 0; i < 4; i++) {
		cout << check[i] << " ";
	}
	cout << '\n';

	return 0;
}