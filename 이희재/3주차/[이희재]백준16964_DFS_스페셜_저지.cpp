#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> nodes[100001];
int expected[100001], subtree_size[100001], level[100001];
int N;
bool checked[100001];

int dfs(int k, int lv) {
	checked[k] = true;
	level[k] = lv;
	int size = 1;

	vector<int>::iterator it;
	for (it = nodes[k].begin(); it != nodes[k].end(); it++) {
		if (checked[*it] == 0) {
			size += dfs(*it, lv+1);
		}
	}

	return subtree_size[k] = size;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)    cin >> expected[i];
	if (expected[1] != 1) {
		cout << "0\n";
		return 0;
	}

	dfs(1, 0);


	for (int i = 1; i <= N; i++) {
		int cur = expected[i];
		int next = i + subtree_size[cur];
		if (next > N)     continue;
		next = expected[next];
		if (level[cur] < level[next]){
			cout << "0\n";
			return 0;
		}
	}
	cout << "1\n";

	return 0;
}