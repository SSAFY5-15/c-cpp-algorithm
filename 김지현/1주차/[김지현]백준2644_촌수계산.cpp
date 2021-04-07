#include <iostream>
#include <queue>

using namespace std;

int people, r;
int prob[2];
int relative[101][101];
int a, b;

queue<int> q;
int visited[101];

void bfs() {
	visited[prob[0]] = 1;
	q.push(prob[0]);

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (pos == prob[1]) return;

		for (int i = 1;i <= people;i++) {
			if (relative[pos][i] == 1 && visited[i] == 0) {
				visited[i] = visited[pos] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> people;
	cin >> prob[0] >> prob[1];
	cin >> r;
	for (int i = 1;i <= r;i++) {
		cin >> a >> b;
		relative[a][b] = relative[b][a] = 1;
	}
	bfs();
	if (visited[prob[1]] == 0) cout << -1;
	else cout << visited[prob[1]] - 1;

	return 0;
}