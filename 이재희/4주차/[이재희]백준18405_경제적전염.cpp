#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 250;
int arr[MAX][MAX];
int n, k;
int s, x, y;
bool visited[MAX][MAX];
bool sp[MAX][MAX];
int dx[] = { -1,+1,0,0 };
int dy[] = { 0,0,-1,+1 };
vector<pair<int,int>> vi[1002];
int flag;

void spread() {
	flag = 0;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		if (arr[i][j] != 0) {
	//			sp[i][j] = true;
	//		}
	//	}
	//}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		if (sp[i][j] == true) {
	//			queue<pair<int, int>> q;
	//			q.push({ i,j });
	//			visited[i][j] = true;

	//			while (!q.empty()) {
	//				int x = q.front().first;
	//				int y = q.front().second;
	//				q.pop();

	//				for (int i = 0; i < 4; i++) {
	//					int nx = x + dx[i];
	//					int ny = y + dy[i];

	//					if (nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == 0 && visited[nx][ny] == false) {
	//						visited[nx][ny] = true;
	//						arr[nx][ny] = arr[x][y];
	//						flag = 1;
	//						//q.push({ nx,ny });
	//					}
	//				}
	//			}
	//		}
	//	}
	//	memset(visited, false, sizeof(visited));
	//}

	vector<pair<int, int>> cpy[1002];
	/*cpy->assign(vi->begin(), vi->end());*/
	/*cpy->resize((int)vi->size());
	copy(vi->begin(), vi->end(), cpy->begin());*/

	for (int i = 1; i <= k; i++) {
		int len = vi[i].size();

		for (int k = 0; k < len; k++) {
			int x = vi[i][k].first;
			int y = vi[i][k].second;

			queue<pair<int, int>> q;
			q.push({ x,y });
			visited[x][y] = true;

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == 0 && visited[nx][ny] == false) {
						visited[nx][ny] = true;
						arr[nx][ny] = arr[x][y];
						cpy[i].push_back({ nx,ny });
						flag = 1;
						//q.push({ nx,ny });
					}
				}
			}
		}
		memset(visited, false, sizeof(visited));
	}

	for (int i = 1; i <= k; i++) {
		int len = cpy[i].size();
		for (int k = 0; k < len; k++) {
			int x = cpy[i][k].first;
			int y = cpy[i][k].second;

			vi[i].push_back({ x,y });
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0) {
				vi[arr[i][j]].push_back({ i,j });
			}
		}
	}
	scanf("%d %d %d", &s, &x, &y);
	while (s--) {
		printf("%d\n", s);
		spread();
		if (flag == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", arr[i][j]);
			}
			printf("\n");
		}
	}
	printf("%d\n", arr[x - 1][y - 1]);
	return 0;
}