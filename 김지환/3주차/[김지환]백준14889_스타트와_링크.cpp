#include <iostream>
#include <math.h>
using namespace std;
unsigned stk = 0, mem[11000000] = { 0, };
int N, ARR[20][20] = { 0, }, N2 =0;

int f(int s, int l) {
	int i, j, ret = 0, mn = 1e9;
	if (s == N2) {
		if (mem[stk] != 0) return 1e9;
		else {
			mem[stk] = 1;
			mem[(1<<N+1)-stk-1] = 1;
		}
		
		int sum[2] = { 0, };
		for (i = 0; i < N; i++) {
			int ii = 1 << i;
			for (j = i +1 ; j < N; j++) {
				int jj = 1 << j;
				if (((stk&ii)==0) == ((stk & jj) ==0)) {
					int value = ((stk & ii) == 0) ? 0 : 1;
					sum[value] += (ARR[i][j] + ARR[j][i]);
				}
			}
		}

		return abs(sum[0] - sum[1]);
	}
	else {
		for (i = l; i < N; i++) {
			unsigned int cur = 1 << i;
			stk |= cur;
			ret = f(s + 1, i+1);
			if (mn > ret) mn = ret;
			stk &= ((1<<N+1)-1 -cur);
		}
	}
	return mn;
}
int main() {
	int i, j;
	cin >> N;
	N2 = N/2;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> ARR[i][j];
		}
	}
	cout << f(0, 0) << endl;
	return 0;
}
