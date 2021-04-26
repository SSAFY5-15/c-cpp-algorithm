#include <iostream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;
int M, K, ARR[201][201] = { 0, }, S, X, Y;
typedef struct _NODE {
	int value;
	pair<int, int> pos;
} node;
vector<node>v;
int d[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };
int cmp(const void *a, const void *b) {
	int aa = ((node *)a)->value;
	int bb = ((node *)b)->value;

	if (aa > bb)return 1;
	else if (aa == bb) return 0;
	else return -1;

}
void f() {
	int i, cnt=0;
	while (S--) {
		//cnt = v.size();
		if(!v.empty())cnt = v.size();
		else cnt = 0;
		while (cnt--) {
			//큐에서 하나 빼기
			node cur = v.front();
			int cv = cur.value, cy = cur.pos.first, cx = cur.pos.second;
			v.erase(v.begin());

			//바이러스 심기
			for (i = 0; i < 4; i++) {
				int ny = cy + d[i][0], nx = cx + d[i][1];
				if (ny <1 || ny > M || nx < 1 || nx > M || ARR[ny][nx] != 0)continue;
				ARR[ny][nx] = cv;
				v.push_back({ cv, make_pair(ny, nx) });
			}


			for (i = 1; i <= M; i++) {
				for (int j = 1; j <= M; j++) {
					cout << setw(4) << ARR[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		//cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl; 
	}
}
int main() {
	int i, j;
	cin >> M >> K;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= M; j++) {
			cin >> ARR[i][j];
			if (ARR[i][j]) v.push_back({ ARR[i][j], make_pair(i, j) });
		}
	}
	cin >> S >> X >> Y;
	if (!v.empty()) {
		qsort(&v[0], v.size(), sizeof(node), cmp);
		f();
	}
	cout << ARR[X][Y] << endl;
}