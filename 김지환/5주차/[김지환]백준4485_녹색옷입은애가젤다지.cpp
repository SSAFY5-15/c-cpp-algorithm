#include <iostream>
#include <queue>
using namespace std;

int ARR[130][130] = { 0, }, N;
int D[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} }; // 상 우 하 좌
int dist[130][130] = { 0, }; // 갱신할 거리

//https://koosaga.com/9
typedef struct _node{
	int v;
	int y;
	int x;
} node; // value, y, x

struct cmp {
	bool operator()(const node& n1, const node &n2) {
		return n1.v > n2.v; //참인 순서대로 비교
	}
};

priority_queue<node, vector<node>, cmp> q;

int djk() {
	
	q.push({ ARR[1][1],1,1 });
	dist[1][1] = ARR[1][1];
	
	while (!q.empty()) {
		node top = q.top(); q.pop();
		int cv = top.v, cy = top.y, cx = top.x;
		for (int i = 0; i < 4; i++) {
			int ny = cy + D[i][0], nx = cx + D[i][1], nv = cv + ARR[ny][nx];
			if (ny<1 || ny > N || nx <1 || nx > N) continue;
			if (dist[ny][nx] > nv) {
				dist[ny][nx] = nv;
				q.push({ nv, ny, nx });
			}		
		}
	}
	return 0;
}
int main() {
	int cnt = 0;
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> ARR[i][j];
				dist[i][j] = 1e9;
			}
		}
		djk();
		cout <<"Problem " << ++cnt << ": " << dist[N][N] << endl;
	}
}

