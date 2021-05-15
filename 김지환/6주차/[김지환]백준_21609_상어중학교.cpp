#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stdio.h>
using namespace std;
int M, N, ARR[22][22] = { 0, };
int D[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int ch_normal[22][22] = { 0, }, ch_rainbow[22][22] = { 0, };

int score = 0, total=0;
typedef struct _blocks {
	int broad = 0;
	int num;
	int y, x;
} Block;

struct cmp {
	bool operator()(const Block &a, const Block &b) {
		//조건문이 참이면 바꿈
		if (a.broad < b.broad) return 1;
		else if (a.broad == b.broad) {
			if (a.num < b.num) return 1;
			else if (a.num == b.num) {
				if (a.y < b.y) return 1;
				else if (a.y == b.y) {
					if (a.x < b.x) return 1;
					else return 0;
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
	}
};


int find_y, find_x, find_num = 0, find_broad = 0;
void find(int cy, int cx, int v, int mode) {
	int i, j, d;
	if (mode == 0) {
		//방문 체크
		if (ARR[cy][cx] == v) {
			//일반 블록일 경우
			ch_normal[cy][cx] = 1;

			//기준 블록 설정
			if (find_y > cy) {
				find_y = cy;
				find_x = cx;
			}
			else if (find_y == cy) {
				if (find_x > cx) {
					find_x = cx;
				}
			}
		}
		else if (ARR[cy][cx] == 0) {
			//무지개 블록일 경우
			find_num++;
			ch_rainbow[cy][cx] = 1;
		}
		//넓이 재기
		find_broad++;
	}
	else {
		//삭제모드
		ARR[cy][cx] = -2;
		score++;
	}

	

	for (d = 0; d < 4; d++) {
		int ny = cy + D[d][0], nx = cx + D[d][1];
		if (ny <1 || ny>M || nx <1 || nx > M) continue;

		if (mode == 0) {
			//방문모드
			if (ARR[ny][nx] == v) {
				if (!ch_normal[ny][nx]) find(ny, nx, v, mode);
			}
			else if (ARR[ny][nx] == 0) {
				if (!ch_rainbow[ny][nx]) find(ny, nx, v, mode);
			}
		}
		else {
			//삭제모드
			if (ARR[ny][nx] == 0 || ARR[ny][nx] == v) find(ny, nx, v, mode);
		}
	}
}
void gravity_column(int y, int x) {
	queue<int> q;
	int piny = y,  cy = y, cv;
	while (cy>=0) {
		cy--;
		if(cy>0)cv = ARR[cy][x];
		if (cy == 0 || cv == -1) {

			int inserty = piny;
			while (!q.empty()) {
				inserty--;
				ARR[inserty][x] = q.front();
				q.pop();
			}
			for (int i = inserty - 1; i > cy; i--) ARR[i][x] = -2;
			piny = cy;
		}
		else if(cv != -2) {
			q.push(cv);

		}
	}
}
void Print() {
	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= M; x++) {
			if (ARR[y][x] != -2) cout << ARR[y][x] << " ";
			else  cout << "  ";
		}
		cout << endl;
	}
}
void Turn() {
	int i, j, buf[22][22] = { 0, };
	for (i = 1; i <= M; i++) {
		for (j = 1; j <=M; j++) {
			buf[i][j] = ARR[j][M-i+1];
		}
	}

	for (i = 1; i <= M; i++) {
		for (j = 1; j <= M; j++) {
			ARR[i][j] = buf[i][j];
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	int i, j, ret, w= 0;
	cin >> M >> N;
	for (i = 1; i <= M; i++) { for (j = 1; j <= M; j++) { cin >> ARR[i][j]; } }
	while (1) {
		//ch 초기화
		for (i = 1; i <= M; i++) { for (j = 1; j <= M; j++) { ch_normal[i][j] = 0; } }
		priority_queue<Block, vector<Block>, cmp> pq;
		//블럭 찾기
		for (int y = 1; y <= M; y++) {
			for (int x = 1; x <= M; x++) {
				
				//시작 조건 = 기준블록 = 일반블록
				if (ARR[y][x] > 0 && !ch_normal[y][x]) {
					//무지개용 블럭 체크 초기화
					for (i = 1; i <= M; i++) { for (j = 1; j <= M; j++) { ch_rainbow[i][j] = 0; } }
					find_y = 21; find_x = 21; find_num = 0; find_broad = 0;
					find(y, x, ARR[y][x], 0);
					
					// 1. 최소 일반블럭 하나 : 충족, 블록 색 : 충족
					// 찾은 무지개블럭 + 일반블럭 >= 2
					if (find_broad >= 2) {
						//cout << "블록 정보 " <<y << " " << x << endl;
						//printf("b : %d / n : %d /  y : %d /  x : %d \n", find_broad, find_num, find_y, find_x);
						pq.push({ find_broad, find_num, find_y,find_x });
					}
					
				}
			}
		}


		//없앨 블록 정하기 pq.top
		if (pq.empty()) break;
		Block target = pq.top(); pq.pop();
		//cout << "타겟 정보 : " << target.broad << "/" << target.num << " / " << target.y << " / " << target.x << endl;

		//블럭 무리 없애기 + 점수 합산
		score = 0;
		find(target.y, target.x, ARR[target.y][target.x],1);
		total += score*score;

		//중력 작용시키기
		for(i=1;i<=M;i++) gravity_column(M+1, i);
		Turn();

		//중력 작용시키기
		for(i=1;i<=M;i++) gravity_column(M+1, i);
	}
	cout << total << endl;
}