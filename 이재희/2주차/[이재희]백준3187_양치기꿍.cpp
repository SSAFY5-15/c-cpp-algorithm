#pragma warning(disable:4996)
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 300;

int arr[MAX][MAX];
int brr[MAX][MAX];
bool visited[MAX][MAX];
bool checked[MAX][MAX];
int cnt = 1;
int howmany[4000][2]; //0: ¾ç, 1: ´Á´ë
int n, m;
int wolf, sheep;

int dx[] = { -1,+1,0,0 };
int dy[] = { 0,0,-1,+1 };

void spread(int x,int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	brr[x][y] = cnt;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false) {
				if (arr[nx][ny] != 1) {
					brr[nx][ny] = cnt;
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	cnt++;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp = 0;
			scanf(" %c", &temp);
			if (temp == '.') arr[i][j] = 0;
			if (temp == '#') arr[i][j] = 1;
			if (temp == 'v') arr[i][j] = 2; //´Á´ë
			if (temp == 'k') arr[i][j] = 3; //¾ç
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false && arr[i][j]!=1) {
				spread(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (brr[i][j] > 0) {
				int area_num = brr[i][j];
				if (arr[i][j] == 2) {
					howmany[area_num][0]++;
				}
				if (arr[i][j] == 3) {
					howmany[area_num][1]++;
				}
			}
		}
	}

	for (int i = 1; i < cnt; i++) {
		int wolf_num = howmany[i][0];
		int sheep_num = howmany[i][1];

		if (wolf_num < sheep_num) sheep += sheep_num;
		else wolf += wolf_num;
	}

	

	printf("%d %d\n", sheep, wolf);

	return 0;
}