#include <iostream>
#define MIN(a,b) ((a)>(b) ? (b):(a))
using namespace std;
int T;
int dp[4];
int main() {
	cin >> T;
	int a, b, c;
	int ta, tb, tc;
	cin >> a >> b >> c;
	dp[0] = a;
	dp[1] = b;
	dp[2] = c;
	for (int i = 0; i < T-1; i++) {
		cin >> a >> b >> c;
		ta = dp[0]; tb = dp[1]; tc = dp[2];
		dp[0] = MIN(tb, tc) + a;
		dp[1] = MIN(ta, tc) + b;
		dp[2] = MIN(ta, tb) + c;
	}
	int ans = MIN(MIN(dp[0], dp[1]), dp[2]);
	cout << ans << endl;


	return 0;
}