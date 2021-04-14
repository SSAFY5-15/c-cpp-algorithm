// 3187. 양치기 꿍
#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;

int r, c;
char mapp[250][251] = {'\0',};
bool visited[250][251] = {false, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
map<char, int> res;

void bfs(int i, int j) {
	int v = 0;
	int k = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	if (mapp[i][j] == 'v') v++;
	else if(mapp[i][j] == 'k') k++;
	mapp[i][j] = '#';

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int p = 0; p < 4; p++) {
			int xx = x + dx[p]; 
			int yy = y + dy[p];
			if ((xx < 0) || (xx >= c) || (yy < 0) || (yy >= r) || mapp[yy][xx]=='#') continue;
			q.push(make_pair(yy, xx));
			if (mapp[yy][xx] == 'v') v++;
			else if (mapp[yy][xx] == 'k') k++;
			mapp[yy][xx] = '#';
		}

	}
	// v,k 비교, 더 큰 거 리턴
	if (v < k) res['k'] += k;
	else if (v == 0 && k == 0) return;
	else res['v'] += v;
}

int main() {
	res['v'] = 0;
	res['k'] = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> mapp[i];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mapp[i][j] != '#') bfs(i, j);
		}
	}
	cout << res['k'] << ' ' << res['v'];
	return 0;
}