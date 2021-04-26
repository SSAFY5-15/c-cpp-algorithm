#include <iostream>
#include <cstring>

#define MIN(A,B) ((A)<(B)?(A):(B))
using namespace std;
int cost[1000][3], table[1000][3];
int N;

void init() {
	for (int i = 0; i < 1000; i++) {
		memset(cost[i], 0, sizeof(int) * 3);
		memset(table[i], 0, sizeof(int) * 3);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	for (int j = 0; j < 3; j++)
		table[0][j] = cost[0][j];

	for (int i = 1; i < N; i++) {
		table[i][0] = MIN(table[i - 1][1] + cost[i][0], table[i - 1][2] + cost[i][0]);
		table[i][1] = MIN(table[i - 1][0] + cost[i][1], table[i - 1][2] + cost[i][1]);
		table[i][2] = MIN(table[i - 1][0] + cost[i][2], table[i - 1][1] + cost[i][2]);
	}

	cout << MIN(table[N - 1][0], MIN(table[N - 1][1], table[N - 1][2])) << '\n';

	return 0;
}