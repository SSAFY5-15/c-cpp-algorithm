#include <iostream>
#include <cstring>
using namespace std;

int map[8][8];
int N, M;
int num_cctv, cnt_blind, min_blind;

// map ���� ���� �� �� �� ��
// �ð�������� 90���� ȸ���ϴ� ����
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// cctv ���� ���� ���� ������ ���� ����
// ���������� �ð�������� 90���� ȸ���ϴ� ����
int direction[5][4] = {
	{ 1, 0, 0, 0 },
	{ 1, 0, 1, 0 },
	{ 1, 0, 0, 1 },
	{ 1, 0, 1, 1 },
	{ 1, 1, 1, 1 }
};

// cctv���� ������ �����ִ� ����ü
struct cctv_stat {
	int y;
	int x;
	int type;
} cctv[8];

// init() : map�� �������� �ʱ�ȭ
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
		// �� cctv�� ������ ����
		for (int i = 0; i < 4; i++) {
			// ������ ������ �������� cctv�� ������ �� �ִ� ������ �˻�
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

			// �ش� ���� ���� ���ø� ����
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

	// N, M, map�� ���� ������ �޴´�.
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	// map[][]���� �簢������ ���� cctv�� ������ ã��
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
	// ����� min_blind�� �ƹ� ��ҵ� �������� ���� ���� ������ �ʱ�ȭ
	min_blind = cnt_blind;

	dfs(0);

	cout << min_blind << '\n';

	return 0;
}