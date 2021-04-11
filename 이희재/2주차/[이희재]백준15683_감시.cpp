#include <iostream>
#include <cstring>
using namespace std;

int map[8][8];
int N, M;
int num_cctv, cnt_blind, min_blind;

// map 기준 방향 상 우 하 좌
// 시계방향으로 90도씩 회전하는 방향
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// cctv 기준 방향 앞쪽 오른쪽 뒤쪽 왼쪽
// 마찬가지로 시계방향으로 90도씩 회전하는 기준
int direction[5][4] = {
	{ 1, 0, 0, 0 },
	{ 1, 0, 1, 0 },
	{ 1, 0, 0, 1 },
	{ 1, 0, 1, 1 },
	{ 1, 1, 1, 1 }
};

// cctv들의 정보를 갖고있는 구조체
struct cctv_stat {
	int y;
	int x;
	int type;
} cctv[8];

// init() : map과 변수들을 초기화
void init() {
	for (int i = 0; i < 8; i++)
		memset(map[i], 0, sizeof(int) * 8);
	num_cctv = 0;
	cnt_blind = 0;
}

void dfs(int k) {
	if (k == num_cctv) {
		if (cnt_blind < min_blind)
			min_blind = cnt_blind;
		return;
	}
	else {
		// 각 cctv의 방향을 설정
		for (int i = 0; i < 4; i++) {
			// 설정된 방향을 기준으로 cctv가 감시할 수 있는 영역을 검사
			for (int j = 0; j < 4; j++) {
				if (direction[cctv[k].type][j] == 1) {
					int y = cctv[k].y;
					int x = cctv[k].x;
					int d = (i + j) % 4;

					while (1) {
						y += dy[d];
						x += dx[d];
						if (y < 0 || y >= N || \
							x < 0 || x >= M)
							break;
						else if (map[y][x] == 0) {
							cnt_blind--;
							map[y][x] -= 1;
						}
						else if (map[y][x] < 0)
							map[y][x] -= 1;
						else if (map[y][x] == 6)    break;
					}
				}
			}

			dfs(k + 1);

			// 해당 기준 방향 감시를 해제
			for (int j = 0; j < 4; j++) {
				if (direction[cctv[k].type][j] == 1) {
					int y = cctv[k].y;
					int x = cctv[k].x;
					int d = (i + j) % 4;

					while (1) {
						y += dy[d];
						x += dx[d];
						if (y < 0 || y >= N || \
							x < 0 || x >= M)
							break;
						else if (map[y][x] == -1) {
							cnt_blind++;
							map[y][x] += 1;
						}
						else if (map[y][x] < -1)
							map[y][x] += 1;
						else if (map[y][x] == 6)    break;
					}
				}
			}

			if (cctv[k].type == 4)    break;
			else if (cctv[k].type == 1 && i == 1)    break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	init();

	// N, M, map에 대한 정보를 받는다.
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	// map[][]에서 사각지대의 수와 cctv의 정보를 찾음
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				cnt_blind++;
			else if (map[i][j] > 0 && map[i][j] < 6) {
				cctv[num_cctv].y = i;
				cctv[num_cctv].x = j;
				cctv[num_cctv++].type = map[i][j] - 1;
			}
		}
	// 결과값 min_blind를 아무 장소도 감시하지 못할 때의 값으로 초기화
	min_blind = cnt_blind;

	dfs(0);

	cout << min_blind << '\n';

	return 0;
}