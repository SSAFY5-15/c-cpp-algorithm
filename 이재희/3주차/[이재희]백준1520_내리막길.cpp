#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 550;

int n, m;
int arr[MAX][MAX];
int brr[MAX][MAX];
bool visited[MAX][MAX];
int ans;

int dx[] = { -1,+1,0,0 };
int dy[] = { 0,0,-1,+1 };


int now(int x, int y) {
	if (x == 0 && y == 0) return 1;

	int a[4]={0, };
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] > arr[x][y]) {
			if(visited[nx][ny]==false)	a[idx++] = now(nx, ny);
			else a[idx++] = brr[nx][ny];
		}
	}

	int sum = a[0] + a[1] + a[2] + a[3];
	brr[x][y] = sum;
	visited[x][y] = true;
	return sum;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	ans = now(n - 1, m - 1);

	printf("%d\n", ans);

	return 0;
}