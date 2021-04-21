#include <iostream>

using namespace std;
int N;
int B[100001][3];
int order[100002];
int ans = 0;
int cnt = 1;

void sol(int s) {
	if (cnt == N) {
		ans = 1;
		return;
	}
	for (int i = 0; i < N - 1; i++) {
		if (B[i][0] == s && B[i][1] == order[cnt]) {
			cnt++;
			sol(B[i][1]);
			i = -1;
		}
		else if (B[i][0] == order[cnt] && B[i][1] == s) {
			cnt++;
			sol(B[i][0]);
			i = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> B[i][j];
		}
	}
	for (int i = 0; i < N; i++) cin >> order[i];

	if (order[0] == 1) sol(1);
	cout << ans << endl;
	return 0;
}