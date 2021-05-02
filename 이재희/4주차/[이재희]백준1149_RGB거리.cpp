#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1050;
int arr[MAX][3];
int N;
int dp[MAX][3];
int rgb[MAX];
int minn = 987654321;
void solve() {
	for (int i = 1; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	solve();

	//if (dp[N - 1] < minn) minn = dp[N - 1];
	//printf("%d\n", dp[N - 1]);
	minn = min(dp[N][0], dp[N][1]);
	minn = min(minn, dp[N][2]);

	printf("%d\n", minn);
	
	return 0;
}