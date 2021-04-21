#include <iostream>
using namespace std;
int M, N, ARR[501][501] = { 0 };
int D[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };
int mem[501][501] = { 0 , };
//f�� y,x ���� Ž���� �����ϴ� �Լ�. ���������� ������ �� �ִ� �������� ��ȯ.

//mem[y][x] y,x���� ���������� ������ �� �ִ� ������.
//�ѹ� Ž���� ���� ������ mem���� ������ �湮��������.
int f(int cy, int cx) {
	int d, sum = 0;
	int cv = ARR[cy][cx];

	//��� �ǵ��ư��� ����
	ARR[cy][cx] = 0;
	for (d = 0; d < 4; d++) {
		int ny = cy + D[d][0], nx = cx + D[d][1], nv = ARR[ny][nx];

		//4�� �� �ܰ��� ����ų�, ���� �������� ���� ������ Ž������ ����.
		if (nv == 0 || cv <= nv) continue;

		//Ž���ߴ� ������ mem���� ����
		 sum += (mem[ny][nx] != -1) ? (mem[ny][nx]) : f(ny, nx);
	}
	ARR[cy][cx] = cv;

	//y,x �������� ������ �� �ִ� ������(sum) ���
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