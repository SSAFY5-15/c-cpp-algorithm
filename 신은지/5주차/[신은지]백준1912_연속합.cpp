#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000] = { 0, };
int dp[100000] = { 0, };
int res;

int main() {
	cin >> n;
	for (int i = 0;i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	res = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1], 0) + arr[i];
		if (dp[i] > res) res = dp[i];
	}
	cout << res;
}