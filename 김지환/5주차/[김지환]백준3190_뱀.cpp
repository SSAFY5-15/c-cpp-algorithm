#include <iostream>
using namespace std;
typedef struct _cmd {
	int i;
	char d;
}cmd;
cmd CMD[111];
int N, ARR[111][111] = { 0, }, NCMD, D[5][2] = { {0, 0, }, { -1,0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int hy=1, hx = 1, ty = 1, tx = 1, cd = 2, icmd=0;
int main() {
	int i, j, t1, t2, t3;
	cin >> N;
	cin >> t1;
	while (t1--) {
		cin >> t2 >> t3;
		ARR[t2][t3] = 5;
	}
	cin >> NCMD;
	for (i = 0; i < NCMD; i++) {
		cin >> CMD[i].i >> CMD[i].d;
	}

	t1 = 0; //�����
	ARR[hy][hx] = 2;
	while (1) {
		//if (t1++ == 10) break;
		t1++;
		//�Ӹ� ���б�
		int nhy = hy + D[cd][0], nhx = hx + D[cd][1], nhv;
			//���̴�
				//End
		if (nhy <1 || nhy > N || nhx < 1 || nhx > N) break;
		if (ARR[nhy][nhx] != 5 && ARR[nhy][nhx] != 0) break;
		//�����
			//�Ӹ� �̵�
			//cd �����
		//����� �ƴϴ�
			//+������ �ű��
		hy = nhy; hx = nhx; nhv = ARR[nhy][nhx];
		
		if (nhv != 5) {
			//���� ��ġ�� d�� ���� ó��
			int dy = D[ARR[ty][tx]][0], dx = D[ARR[ty][tx]][1];
			ARR[ty][tx] = 0;
			ty += dy; tx += dx;
		}
		

		//ȸ��
		if (icmd < NCMD) {
			if (CMD[icmd].i == t1) {
				if (CMD[icmd].d == 'L') { cd--; cd = (cd < 1)? 4 : cd; }
				else if (CMD[icmd].d == 'D') { cd++; cd = (cd > 4) ? 1 : cd; };
				icmd++;
			}
		}
		//������ ����� ���� �����
		ARR[hy][hx] = cd;
		/*cout << t1 << " " << cd << endl;
		for (int p1 = 1; p1 <= N; p1++) {
			for (int p2 = 1; p2 <= N; p2++) {
				cout << ARR[p1][p2] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	cout << t1 << endl;
}

/*
2
3
1 2
2 1
2 2
3
1 D
2 D 
3 D
*/