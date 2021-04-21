#include <iostream>
using namespace std;
int M, N, ARR[501][501] = { 0 };
int D[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };
int mem[501][501] = { 0 , };
//f는 y,x 에서 탐색을 시작하는 함수. 목적지까지 도착할 수 있는 가짓수를 반환.

//mem[y][x] y,x에서 목적지까지 도착할 수 있는 가짓수.
//한번 탐색을 끝낸 지점은 mem값을 참고해 방문하지않음.
int f(int cy, int cx) {
	int d, sum = 0;
	int cv = ARR[cy][cx];

	//경로 되돌아가기 방지
	ARR[cy][cx] = 0;
	for (d = 0; d < 4; d++) {
		int ny = cy + D[d][0], nx = cx + D[d][1], nv = ARR[ny][nx];

		//4방 중 외곽을 벗어나거나, 현재 지점보다 낮은 지점은 탐색하지 않음.
		if (nv == 0 || cv <= nv) continue;

		//탐색했던 지점은 mem변수 참고
		 sum += (mem[ny][nx] != -1) ? (mem[ny][nx]) : f(ny, nx);
	}
	ARR[cy][cx] = cv;

	//y,x 지점에서 도착할 수 있는 가짓수(sum) 기록
	mem[cy][cx] = sum;
	return sum;
}
int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> ARR[i][j];
			mem[i][j] = -1;
		}
	}
	mem[M][N] = 1;
	cout << f(1, 1) << endl;
}

/*
3 3 
5 4 3 
4 3 2
3 2 1
*/