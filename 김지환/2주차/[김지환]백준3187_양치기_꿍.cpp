#include <iostream>
#include <queue>
using namespace std;
int M, N, D[4][2] = { {-1, 0}, {0, 1},{1, 0}, {0, -1} };
char arr[251][251] = { 0, };
int sk =0, sv = 0;
void f(int sy, int sx) {
	int ck=0, cv = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	if (arr[sy][sx] == 'k') ck++;
	else if (arr[sy][sx] == 'v') cv++;
	arr[sy][sx] = '#';

	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = D[d][0] + cy, nx = D[d][1] + cx;
			if (arr[ny][nx] != '#' && 1<=ny && ny <= M && 1<= nx && nx <= N) {
				if (arr[ny][nx] == 'k') ck++;
				else if (arr[ny][nx] == 'v') cv++;

				q.push(make_pair(ny, nx));
				arr[ny][nx] = '#';
			}
		}
	}
	//for (int i = 1; i <= M; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	if (ck > cv) sk += ck;
	else sv += cv;
}
int main() {
	int i, j;
	cin >> M >> N;
	for (i = 1; i <= M; i++) for (j = 1; j <= N; j++) cin >> arr[i][j];
	for (i = 1; i <= M; i++) for (j = 1; j <= N; j++) if(arr[i][j] != '#')f(i, j);
	cout << sk << " " << sv << endl;
}