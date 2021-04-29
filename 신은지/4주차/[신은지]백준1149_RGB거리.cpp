#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cost[1001][3] = { 0, };

int main() {
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int i = 2; i < n + 1; i++) {
			for (int j = 0; j < 3; j++)
				cost[i][j] += min(cost[i - 1][(j + 1) % 3], cost[i - 1][(j + 2) % 3]);
	}
	cout << min(min(cost[n][0], cost[n][1]), cost[n][2]);
}