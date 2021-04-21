#include <iostream>

using namespace std;
int N;
int B[24][24];
int check[24];
int mn;
void dfs(int dep, int s) {
	if (mn == 0 || mn != -1 && check[0] == 0) return;
	if (dep == N / 2) {
		int temp = 0;
		int temp2 = 0;
		for (int i = 0; i < N; i++) {
			if (check[i] == 1) {
				for (int j = i + 1; j < N; j++) {
					if (check[j] == 1) {
						temp += B[i][j];
						temp += B[j][i];
					}
				}
			}
			else {
				for (int j = i + 1; j < N; j++) {
					if (check[j] == 0) {
						temp2 += B[i][j];
						temp2 += B[j][i];
					}
				}
			}
		}
		if (temp > temp2) temp = temp - temp2;
		else temp = temp2 - temp;

		if (mn == -1 || temp < mn) mn = temp;
		return;
	}

	for (int i = s; i <= N / 2 + dep; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			dfs(dep + 1, i + 1);
			check[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> B[i][j];
		}
	}
	mn = -1;
	dfs(0, 0);
	cout << mn << endl;
	return 0;
}