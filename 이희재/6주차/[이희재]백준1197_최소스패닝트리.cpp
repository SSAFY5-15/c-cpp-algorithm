#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> v[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[10001];
int V, E, cnt, weight;

void init() {
	memset(visited, false, sizeof(bool) * 10001);
	cnt = 0;
	weight = 0;
}

void set_start() {
	visited[1] = true;
	cnt++;
	for (vector<pair<int, int>>::iterator iter = v[1].begin(); iter != v[1].end(); iter++) {
		pair<int, int> tmp = *iter;
		if (visited[tmp.second] == false)    pq.push({ tmp.first, tmp.second });
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	init();

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ C,B });
		v[B].push_back({ C,A });
	}

	set_start();
	if (V != 1) {
		while (1) {
			pair<int, int> tmp = pq.top();
			pq.pop();
			while (visited[tmp.second] == true) {
				tmp = pq.top();
				pq.pop();
			}
			weight += tmp.first;
			cnt++;
			visited[tmp.second] = true;
			if (cnt == V)    break;
			int node = tmp.second;

			for (vector<pair<int, int>>::iterator iter = v[node].begin(); iter != v[node].end(); iter++) {
				pair<int, int> tmp = *iter;
				if (visited[tmp.second] == false)    pq.push({ tmp.first, tmp.second });
			}
		}
	}
	cout << weight << '\n';
	return 0;
}