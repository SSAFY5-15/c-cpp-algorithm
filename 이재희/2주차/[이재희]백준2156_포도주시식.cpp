#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 10000;

int arr[MAX];
int dp[MAX];
int n;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	for (int i = 2; i < n; i++) {
		int result = 0;
		result = max(dp[i - 2] + arr[i],dp[i-1]);
		result = max(dp[i - 3] + arr[i] + arr[i - 1], result);
		dp[i] = result;
	}

	printf("%d\n", dp[n-1]);

	return 0;
}