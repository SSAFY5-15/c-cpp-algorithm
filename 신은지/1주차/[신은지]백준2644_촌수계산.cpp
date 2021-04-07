#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int num;
int a, b;
vector<int> arr[101];

int bfs(int start, int dest) {
	int dist[101] = { 0, };
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (node == dest) {
			return dist[dest];
		}
		int size = arr[node].size();
		for (int i = 0; i < size; i++) {
			int next = arr[node][i];

			if (!dist[next]) {
				q.push(next);
				dist[next] = dist[node] + 1;
			}
		}
	}
	return -1;
}

int main() {
	int a, b, m;
	cin >> num >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	cout << bfs(a, b);
	return 0;
}