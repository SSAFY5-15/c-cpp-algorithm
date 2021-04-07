#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int k;
vector<int> set;

void print(int* arr) {
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void dfs(int idx, int d, int* arr) {
	if (d == 6) print(arr);
	for (int i = idx; i < k; i++) {
		arr[d] = set[i];
		dfs(i + 1, d + 1, arr);
		if (k - i == 6 - d) break;
	}
}

int main() {
	while (1) {
		cin >> k;
		if (k == 0) break;
		set.clear();
		for (int i = 0; i < k; i++) {
			int temp;
			cin >> temp;
			set.push_back(temp);
		}
		int arr[6] = { 0, };
		dfs(0, 0, arr);
		cout << '\n';
	}
	return 0;
}