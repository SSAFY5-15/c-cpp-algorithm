#include <iostream>
using namespace std;
int N, cost[1111][3] = { 0, }, mn = 1e9;
int arr[3][2] = { {1,2},{0,2}, {0,1} };
int mem[1111][3] = { 0, };

void f2(int n) {
	if (n == N + 1) return;
	for (int i = 0; i < 3; i++) {
		int ret = 1e9;
		for (int j = 0; j < 2; j++) {
			if (ret > mem[n-1][arr[i][j]])ret = mem[n-1][arr[i][j]];
		}
		mem[n][i] = ret + cost[n][i];
	}
	f2(n + 1);
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 2; j++) {
			cin >> cost[i][j];
		}
	}
	f2(0);

	for (int i = 0; i < 3; i++) if (mn > mem[N][i]) mn = mem[N][i];
	cout << mn << endl;
}