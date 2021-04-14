#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num;
vector<int> podo;
vector<int> dp;

int main() {
	int res = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		podo.push_back(temp);
	}
	for (int i = 0; i < num; i++) {
		if (i == 0) dp.push_back(podo[0]);
		else if (i == 1) dp.push_back(podo[0] + podo[1]);
		else if (i == 2) {
			int d1 = max(podo[0], podo[1]) + podo[2];
			dp.push_back(max(d1, dp[1]));
		}
		else {
			int d1 = max(dp[i - 2], dp[i - 3] + podo[i - 1]) + podo[i];
			dp.push_back(max(max(dp[i-2],dp[i-1]),d1));
		}
        if (dp[i] > res) res = dp[i];
	}
	cout << res;
	return 0;
}