#include <iostream>
#include <queue>
using namespace std;

int N, M;
char farm[250][250];
int visited[250][250];
int s, w;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void bfs(int a, int b) {
	int ss = 0, sw = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = 1;
	if (farm[a][b] == 'k')ss++;
	if (farm[a][b] == 'v')sw++;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny]) {
				if (farm[nx][ny] == 'k') {
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					ss++;
				}
				else if (farm[nx][ny] == 'v') {
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					sw++;
				}
				else if (farm[nx][ny] == '.') {
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}	
	}
	if (ss > sw) s += ss;
	else w += sw;
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> farm[i][j];

	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			if (farm[i][j] != '#' && visited[i][j] == 0)  bfs(i, j);

	cout << s << " " << w;

	return 0;
}