#include <iostream>
#include <string.h>

using namespace std;
int ch[11];
int k;
char B[22];
long long int ans;
long long int mn = 99999999999;
long long int mx = 0;
char SMX[11];
char SMN[11];

void dfs(int dep, int st, int ed) {
	if (dep == k + 1) {
		ans = 0;
		for (int i = 0; i <= k; i++) {
			ans = ans * 10 + B[i * 2] - '0';
		}
		if (ans > mx) mx = ans;
		if (ans < mn) mn = ans;
		return;
	}
	for (int i = st; i <= ed; i++) {
		if (ch[i] == 0) {
			B[dep * 2] = i + '0';
			if (dep != 0) {
				if (B[dep * 2 - 1] == '<' && B[dep * 2 - 2] < B[dep * 2] || B[dep * 2 - 1] == '>' && B[dep * 2 - 2] > B[dep * 2]) {
					ch[i] = 1;
					dep++;
					dfs(dep, st, ed);
					dep--;
					ch[i] = 0;
				}
			}
			else {
				ch[i] = 1;
				dep++;
				dfs(dep, st, ed);
				dep--;
				ch[i] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> k;
	for (int i = 1; i < k * 2; i += 2) cin >> B[i];
	dfs(0, 0, 9);
	int temp;
	for (int i = k; i >= 0; i--) {
		temp = mx % 10;
		mx /= 10;
		SMX[i] = temp + '0';
	}
	for (int i = k; i >= 0; i--) {
		temp = mn % 10;
		mn /= 10;
		SMN[i] = temp + '0';
	}
	cout << SMX << '\n' << SMN << endl;
	return 0;
}