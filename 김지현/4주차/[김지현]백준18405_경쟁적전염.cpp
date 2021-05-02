#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, k;
int square[200][200];
vector<tuple<int, int, int>> v;
queue<tuple<int, int, int>> q;
int s, x, y;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void solve() {
	for (const auto& vi : v) q.push(vi);
	int a, b, c;
	while (s != 0) {
		int q_size = q.size();
		for (int t = 0;t < q_size;t++) {
			tie(a, b, c) = q.front();
			q.pop();

			for (int i = 0;i < 4;i++) {
				int nx = b + dx[i];
				int ny = c + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < n && square[nx][ny] == 0) {
					square[nx][ny] = a;
					q.push({ a,nx,ny });
				}
			}
		}
		s--;
	}

}

int main() {
	cin >> n >> k;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++) {
			cin >> square[i][j];
			if (square[i][j])
				v.push_back({ square[i][j],i,j });
		}
	cin >> s >> x >> y;
	
	sort(v.begin(), v.end());
	solve();
	cout << square[x - 1][y - 1] << endl;

	return 0;
}