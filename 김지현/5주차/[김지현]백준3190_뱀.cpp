#include <iostream>
#include <queue>
using namespace std;

int n, k, l, a, b, x, lp, lo;
char c;
int sec = 0;
int board[101][101] = { 0, };
int apple[101][101] = { 0, };
queue<pair<int, char>> q;
deque<pair<int, int>> dq;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1}, };//¿ìÇÏÁÂ»ó
int now_dir = 0;

int solve(int p,int o) {
	if (!sec) lp = lo = 0;
	if (!q.empty()&&sec == q.front().first) {
		if (q.front().second == 'D') {
			if (now_dir == 3) now_dir = 0;
			else now_dir++;
		}else if (q.front().second == 'L') {
			if (now_dir == 0) now_dir = 3;
			else now_dir--;
		}
		q.pop();
	}
	sec++;
	int nx = p + dir[now_dir][1];
	int ny = o + dir[now_dir][0];
	if (board[nx][ny] || nx<1 || nx>n || ny<1 || ny>n) {
		return 0;
	}
	if (!board[nx][ny] && !apple[nx][ny]) {
		board[dq.back().first][dq.back().second] = 0;
		dq.pop_back();
	}
	dq.push_front({ nx,ny });
	board[nx][ny] = 1;
	apple[nx][ny] = 0;
	solve(nx, ny);
	return 0;
}

int main() {
	cin >> n;
	cin >> k;
	board[1][1] = 1;//¹ì
	dq.push_front({ 1,1 });
	for (int i = 1;i <= k;i++) {
		cin >> a >> b;
		apple[a][b] = 1;//»ç°ú
	}
	cin >> l;
	for (int i = 1;i <= l;i++) {
		cin >> x >> c;
		q.push(make_pair(x,c));
	}

	solve(1,1);
	cout << sec << endl;

	return 0;
}