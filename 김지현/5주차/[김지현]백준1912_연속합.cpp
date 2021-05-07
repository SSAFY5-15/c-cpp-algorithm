#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];
int dp[100000];
int result = 0;

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) cin >> arr[i];

	result = dp[0] = arr[0];
	for (int i = 1;i < n;i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(dp[i], result);
	}

	cout << result;

	return 0;
}