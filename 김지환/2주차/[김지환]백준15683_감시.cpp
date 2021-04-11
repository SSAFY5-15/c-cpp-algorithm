#include <iostream>
using namespace std;
int M, N, ARR[10][10] = { 0, }, coords[10][3] = { 0, }, NUM = 1;
int D[4][2] = { { -1,0 }, {0,1},{1,0},{0,-1} };
int D2[6][5] = { {0},
	{1,0},
{ 2, 0,2},
{2, 0,1},
{3, 0, 1, 2},
{4,0,1,2,3}
};

int f(int s, int arr[][10], int value) {
	int ret, mx = 1e9;
	int i, j, d, d2;
	int buf[4][11] = { 0, };
	if (s == NUM) return value;

	int carr[10][10] = { 0, };
	for (i = 1; i <= M; i++) for (j = 1; j <= N; j++) carr[i][j] = arr[i][j];

	int cy = coords[s][0], cx = coords[s][1], ny = cy, nx = cx; // coords[n][0], [1]
	int cm = coords[s][2], cd2; // coords[n][2];
	int cv = value;
	for (d = 0; d < 4; d++) {
		cv = value;

		//모델별 방향 갱신
		for (d2 = 1; d2 <= D2[cm][0]; d2++) {
			ny = cy; nx = cx;
			int cd2 = (d + D2[cm][d2]) % 4;
			buf[cd2][0] = 0;
			//모델 별 두번재 방향 갱신
			while (1) {
				ny += D[cd2][0]; nx += D[cd2][1];
				if (1 > ny || ny > M || 1 > nx || nx > N)break;
				if (carr[ny][nx] == 6) break;

				//빈공간이었으면 기록해두고 변환
				if (carr[ny][nx] == 0) {
					buf[cd2][++buf[cd2][0]] = 1;
					carr[ny][nx] = -1;
					cv--;
				}
				else {
					buf[cd2][++buf[cd2][0]] = 0;
				}
				//아니었으면 기록안함.
			}

		}
		for (int p1 = 1; p1 <= M; p1++) {
			for (int p2 = 1; p2 <= N; p2++) {
				cout << carr[p1][p2] << " ";
			}
			cout << endl;
		}
		cout << endl;
		// 호출
		ret = f(s + 1, carr, cv);
		if (mx > ret) mx = ret;

		//모델별 방향 갱신 취소
	/*	cout << "s : " << s << "d :  " << d << endl;
		if (s == 1 && d == 0) {
			cout << "zz" << "\n";
		}*/
		for (d2 = 1; d2 <= D2[cm][0]; d2++) {
			ny = cy; nx = cx;
			int cd2 = (d + D2[cm][d2]) % 4;

			//모델 별 두번재 방향 갱신 취소
			for (int idx = 1; idx <= buf[cd2][0]; idx++) {
				ny += D[cd2][0]; nx += D[cd2][1];
				//빈공간이었으면 기록해두고 변환
				if (buf[cd2][idx])carr[ny][nx] = 0;
				//아니었으면 기록안함.
			}
		}


		/* d 방향으로 쭉 뻗기
		while (1) {
			ny += D[d][0]; nx += D[d][1];
			if (1 > ny || ny > M || 1 > nx || nx > N)break;
			if (carr[ny][nx] == 6) break;
			carr[ny][nx] = -1;
		}
		*/

		/*
		for (i = 1; i <= D2[cm][0]; i++) {
			int cd2 = (d + D2[cm][i]) % 3;

		}
		*/
	}

	//for (int p1 = 1; p1 <= M; p1++) {
	//	for (int p2 = 1; p2 <= N; p2++) {
	//		cout << carr[p1][p2] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	return mx;
}
int main() {
	int i, j, value = 0;
	freopen("input.txt", "r", stdin);
	cin >> M >> N;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++, value++) {
			cin >> ARR[i][j];
			if (ARR[i][j] == 6) value--;
			if (ARR[i][j] != 0 && ARR[i][j] != 6) {
				coords[NUM][0] = i;
				coords[NUM][1] = j;
				coords[NUM][2] = ARR[i][j];
				NUM++;
				value--;
			}
		}
	}
	/*cout << value << endl;*/
	/*
	for (int p1 = 1; p1 <= M; p1++) {
		for (int p2 = 1; p2 <= N; p2++) {

		}
	}
	*/
	/*for (int p1 = 1; p1 < NUM; p1++) {
		cout << coords[p1][0] << " ";
	}*/

	cout << f(1, ARR, value) << endl;
}