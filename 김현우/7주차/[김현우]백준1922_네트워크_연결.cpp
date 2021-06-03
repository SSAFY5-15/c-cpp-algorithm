#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[1001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int N, M, a, b, c;


int ch[1001];

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[b].push_back({ c,a });
		graph[a].push_back({ c,b });
	}
	pq.push({ 0,1 });
	int ans = 0;
	while (!pq.empty()) {
		int value = pq.top().first;
		int to = pq.top().second;
		pq.pop();
		if (!ch[to]) {
			ch[to] = 1;
			ans += value;
			for (int i = 0; i < graph[to].size(); i++) {
				int nextValue = graph[to][i].first;
				int nextto = graph[to][i].second;
				if (!ch[nextto]) {
					pq.push({ nextValue,nextto });
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}