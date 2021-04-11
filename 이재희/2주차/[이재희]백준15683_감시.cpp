#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10;
struct cctv {
	int x, y;
	int kind;
	int dir;
};

int n, m;
int arr[MAX][MAX];
int brr[MAX][MAX];
vector<cctv> c;
int num;
int ans = 1e9;

int dx[] = { -1,0,+1,0 };
int dy[] = { 0,+1,0,-1 };
int dircnt[] = { 1,2,2,3,4 };
vector<vector<int>> dirmap = {  {0},{0,+2},{0,+1},{0,1,2},{0,1,2,3} };

void go() {
	memcpy(brr, arr, sizeof(arr));
	for (int i = 0; i < num; i++) {
		int x = c[i].x;
		int y = c[i].y;
		int dir = c[i].dir;
		int kind = c[i].kind - 1; // 0 ~ 4 : cctv // 5 : wall

		for (int k = 0; k < dircnt[kind]; k++) {
			x = c[i].x;
			y = c[i].y;
			dir = dir + dirmap[kind][k];
			
			if (dir >= 4) dir -= 4;
			if (dir < 0) dir += 4;
			//printf("%d ", dir);

			while (true) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx<0 || ny<0 || nx>=n || ny>=m || brr[nx][ny] == 6) break;

				brr[nx][ny] = 8;
				x = nx;
				y = ny;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (brr[i][j] == 0) cnt++;
		}
	}
	if (cnt < ans) ans = cnt;

	return;
}

void solve(int cnt) {
	if (cnt >= num) {
		go();
		return;
	}

	if (c[cnt].kind == 5) solve(cnt + 1);
	else {
		for (int dir = 0; dir < 4; dir++) {
			c[cnt].dir = dir;
			solve(cnt + 1);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);

			if (0 < arr[i][j] && arr[i][j] < 6) {
				c.push_back({ i,j,arr[i][j],0 });
				num++;
			}
		}
	}

	solve(0);	

	printf("%d\n", ans);

	return 0;
}