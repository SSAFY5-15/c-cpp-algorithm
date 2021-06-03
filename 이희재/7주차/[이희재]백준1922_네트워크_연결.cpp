#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int computers[1001];
int N, M, cost;

void init() {
	for (int i = 0; i <= N; i++)    computers[i] = i;
	cost = 0;
}

int Find(int n1) {
	// 루트 노드인 경우
	if (n1 == computers[n1])    return n1;
	return computers[n1] = Find(computers[n1]);
}

void Union(int n1, int n2, int c) {
	n1 = Find(n1);
	n2 = Find(n2);
	// n1 < n2 로 가정
	if (n1 != n2) {
		if (n1 < n2)    computers[n2] = n1;
		else    computers[n1] = n2;
		cost += c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> M;
	init();

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		pq.push({ c, {a, b} });
	}

	while (!pq.empty()) {
		pair<int, pair<int, int>> cur = pq.top();
		pq.pop();
		int a = cur.second.first;
		int b = cur.second.second;
		int c = cur.first;
		Union(a, b, c);
	}
	cout << cost << '\n';
	return 0;
}