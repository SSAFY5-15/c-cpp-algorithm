#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int S, Y, X;
int mapp[201][201];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
struct Virus {
	int sec;
	int y, x;
	Virus(int s, int i, int j) : sec(s), y(i), x(j) {}
};
vector<Virus> q;

int bfs() {
	while (!q.empty()) {
		Virus v = q.front();
		if (v.sec == S || mapp[Y][X] != 0) break;
		q.erase(q.begin());
		for (int i = 0; i < 4; i++) {
			int yy = v.y + dy[i];
			int xx = v.x + dx[i];
			if (xx < 1 || xx > n || yy < 1 || yy > n || mapp[yy][xx] != 0) continue;
			mapp[yy][xx] = mapp[v.y][v.x];
			q.push_back(Virus(v.sec + 1, yy, xx));
		}
	}
	return mapp[Y][X];
}

int main() {
	vector<pair<int, int> > type[1001];
	cin >> n >> k;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> mapp[i][j];
			type[mapp[i][j]].push_back(make_pair(i, j));
		}
	}
	cin >> S >> Y >> X;
	for (int i = 1; i < 1001; i++) {
		for (int j = 0; j < type[i].size(); j++) {
			q.push_back(Virus(0, type[i][j].first, type[i][j].second));
		}
	}
	cout << bfs();
	return 0;
}