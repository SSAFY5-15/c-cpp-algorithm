#include <iostream>
#include <cstring>
using namespace std;

int arr[100000];
int dp[100000];
int n, maximum;

void init() {
	memset(arr, 0, sizeof(int) * 100000);
	memset(dp, 0, sizeof(int) * 100000);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	dp[0] = arr[0];
	maximum = dp[0];
	for (int i = 1; i < n; i++) {
		int tmp = arr[i] + dp[i - 1];
		if (tmp > arr[i])    dp[i] = tmp;
		else    dp[i] = arr[i];
		if (dp[i] > maximum)    maximum = dp[i];
	}

	cout << maximum << '\n';
	return 0;
}