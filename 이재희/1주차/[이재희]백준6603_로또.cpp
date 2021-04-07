#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1000;
int k;
vector<int> v; 
vector<vector<int>> list;

void solve() {
	vector<bool> binary(k);
	fill(binary.end() - 6, binary.end(), true);
	do {
		vector<int> temp;
		for (int i = 0; i < k; i++) {
			if (binary[i] == true) {
				temp.push_back(v[i]);
			}
		}
		list.push_back(temp);
	} while (next_permutation(binary.begin(), binary.end()));
	return;
}

void print() {
	sort(list.begin(), list.end());
	int list_size = list.size();
	for (int i = 0; i < list_size; i++) {
		int len = list[i].size();
		for (int j = 0; j < len; j++) {
			printf("%d ", list[i][j]);
		}
		printf("\n");
	}
	return;
}

int main() {
	while (true) {
		scanf("%d", &k);
		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			int temp;
			scanf("%d", &temp);
			v.push_back(temp);
		}

		solve();
		print();
		printf("\n");

		v.clear();
		list.clear();
	}

	return 0;
}
