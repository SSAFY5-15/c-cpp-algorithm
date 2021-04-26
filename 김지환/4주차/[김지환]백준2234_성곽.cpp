#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int M, N, ARR[51][51] = { 0, }, region[51][51] = { 0, }, answer[3] = { 0, }, area[3000] = { 0, };
int i_region = 0;
/*
ARR = 접근할 수 있는 벽정보
region[y][x] = [y][x] 가 속한 지역 번호
board[y] y지역의 넓이;
answer[3] = 성에 있는 방  개수, 가장 넓은 방, 벽하나를 제거해서 얻는 가장 큰 방 크기
*/

typedef vector < pair<int, pair<int, int>>> dir;
dir d;
/*
1, 0, -1;
2, -1, 0;
4, 0, 1;
8, 1, 0;
*/
int dfs(int cy, int cx, int i_r, int dfs_mode) { 
	/* 
	mode1
		cy, cx가 속한 넓이 반환
	mode2
		cy, cx와 벽하나로 나뉜 좌표 발견시 answer[2]갱신
	*/
	int i, j, ret = 1;
	dir::iterator i_d;
	for (i_d = d.begin(); i_d < d.end(); i_d++) {
		int ny = cy + i_d->second.first, nx = cx + i_d->second.second, mask = i_d->first;
		if (ny < 1 || ny > M || nx < 1 || nx > N) continue;
		
		//mod 1
		if (dfs_mode == 0) {
			if (region[ny][nx] != 0) continue;
			if (!(ARR[cy][cx] & mask)) {
				region[ny][nx] = i_r;
				ret += dfs(ny, nx, i_r, dfs_mode);
			}
		}
		else if(dfs_mode == 1) {
			int cr = region[cy][cx], nr = region[ny][nx];
			if (cr != nr) {
				if (answer[2] < area[cr] + area[nr]) answer[2] = area[cr] + area[nr];
			}
		}
	}

	return ret;
}
void init() {
	d.push_back(make_pair(1, make_pair(0, -1)));
	d.push_back(make_pair(2, make_pair(-1, 0)));
	d.push_back(make_pair(4, make_pair(0, 1)));
	d.push_back(make_pair(8, make_pair(1, 0)));
}
int main() {
	freopen("input.txt", "r", stdin);
	int i, j;
	cin >> N >> M;
	for (i = 1; i <= M; i++) for (j = 1; j <= N; j++) { cin >> ARR[i][j]; }
	init(); 
	
	answer[1] = -1;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			if (!region[i][j]) {

				region[i][j] = ++i_region;
				area[i_region] = dfs(i, j, i_region, 0);

				//답2 갱신
				if (answer[1] < area[i_region]) answer[1] = area[i_region];
			}
		}
	}
	
	answer[0] = i_region;

	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			dfs(i, j, 0, 1);
		}
	}
	for (i = 0; i < 3; i++) cout << answer[i] << endl;
}