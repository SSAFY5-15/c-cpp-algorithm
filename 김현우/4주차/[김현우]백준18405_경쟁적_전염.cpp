#include <iostream>
#include <queue>

using namespace std;

int B[202][202];
int CB[202][202];
static int cnt;
int dx[2][5] = { {1,0,-1,0},{0,1,0,-1} };

typedef struct {
	int k;
	int y;
	int x;
}st;
bool operator<(st t, st u) {
	return t.k > u.k;
}
priority_queue<st>q;


void sol(int S,int N, int K) {
	if (cnt == S) return;
	int temp;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (B[i][j] != 0 && CB[i][j]==0) {
				CB[i][j] = 1;
				for (int l = 0; l < 4; l++) {
					if (B[i + dx[0][l]][j + dx[1][l]] == 0 ) {
						q.push({ B[i][j], i + dx[0][l], j + dx[1][l] });
					}
				}
			}
		}
	}

	while (!q.empty()) {
		st tt = q.top();
		q.pop();
		if (B[tt.y][tt.x] == 0) B[tt.y][tt.x] = tt.k;
	}
	
	cnt++;
	sol(S, N, K);

}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> B[i][j];
		}
	}
	int S, X, Y;
	cin >> S >> X >> Y;
	sol(S, N, K);
	cout << B[X][Y] << endl;
	return 0;
}