#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int office[8][8];
int visited[8][8];
vector<pair<int, int>> vec;
int result = 70;

//ÁÂ¿ì»óÇÏ
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void check(int x, int y, int i, int num)
{
	int nx = x;
	int ny = y;
	while (1) {
		nx += dx[i];
		ny += dy[i];
		if (office[nx][ny] == 6) break;
		if (!(nx >= 0 && nx < N && ny >= 0 && ny < M)) break;
		visited[nx][ny] += num;
	}
}

void change(int a, int i, int num)
{
	int x = vec[a].first;
	int y = vec[a].second;
	int type = office[x][y];
	if (type == 1){
		check(x, y, (i + 1) % 4, num);
	}
	else if (type == 2){
		check(x, y, (i + 1) % 4, num);
		check(x, y, (i + 3) % 4, num);
	}
	else if (type == 3){
		check(x, y, (i + 0) % 4, num);
		check(x, y, (i + 1) % 4, num);
	}
	else if (type == 4){
		check(x, y, (i + 0) % 4, num);
		check(x, y, (i + 1) % 4, num);
		check(x, y, (i + 3) % 4, num);
	}
	else if (type == 5) {
		check(x, y, (i + 0) % 4, num);
		check(x, y, (i + 1) % 4, num);
		check(x, y, (i + 2) % 4, num);
		check(x, y, (i + 3) % 4, num);
	}
}

void solve(int a) {
	if (a == vec.size()) {
		int cnt = 0;
		for (int i = 0; i < N; ++i) 
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] == 0)
					cnt++;
			}
		result = min(result, cnt);
		return;
	}
	for (int i = 0; i < 4; ++i){
		change(a, i, 1);
		solve(a + 1);
		change(a, i, -1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++) {
			cin >> office[i][j];
			visited[i][j] = office[i][j];
			if (office[i][j] != 0 && office[i][j] != 6)
				vec.push_back({ i, j });
		}

	solve(0);
	cout << result << endl;

	return 0;
}