#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int mapp[8][8];
int res = 64;
vector<pair<int, int>> cctv;
int dx[4] = {0, 1, 0, -1}; // ╩С ©Л го аб
int dy[4] = {-1, 0, 1, 0};

//void print(int arr[][8]) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}

int count(int arr[][8]) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void paint(int y, int x, int dir, int arr[][8]) {
	int idx = 1;
	while (y + idx * dy[dir] >= 0 && y + idx * dy[dir] < n && x + idx * dx[dir] >= 0 && x + idx * dx[dir] < m) {
		if (arr[y + idx * dy[dir]][x + idx * dx[dir]] == 6) break;
		else if (arr[y + idx * dy[dir]][x + idx * dx[dir]] == 0) arr[y + idx * dy[dir]][x + idx * dx[dir]] = 9;
		idx++;
	}
}

void search(int idx, int arr[][8]) {
	if (idx == cctv.size()) {
		int temp = count(arr);
		if (temp < res) res = temp;
		return;
	}
	int i = cctv[idx].first;
	int j = cctv[idx].second;
	switch(mapp[i][j]){
	case 1:
		for (int k = 0;k < 4; k++) {
			int new_arr[8][8];
			copy(&arr[0][0], &arr[0][0] + 8 * 8, &new_arr[0][0]);
			paint(i,j,k, new_arr);
			search(idx + 1, new_arr);
		}
		break;
	case 2:
		for (int k = 0; k < 2; k++) {
			int new_arr[8][8];
			copy(&arr[0][0], &arr[0][0] + 8 * 8, &new_arr[0][0]);
			paint(i, j, k, new_arr);
			paint(i, j, k+2, new_arr);
			search(idx + 1, new_arr);
		}
		break;
	case 3:
		for (int k = 0; k < 4; k++) {
			int new_arr[8][8];
			copy(&arr[0][0], &arr[0][0] + 8 * 8, &new_arr[0][0]);
			paint(i, j, k, new_arr);
			paint(i, j, (k+1)%4, new_arr);
			search(idx + 1, new_arr);
		}
		break;
	case 4:
		for (int k = 0; k < 4; k++) {
			int new_arr[8][8];
			copy(&arr[0][0], &arr[0][0] + 8 * 8, &new_arr[0][0]);
			for (int p = 0; p < 4; p++) {
				if (k == p) continue;
				paint(i, j, p, new_arr);
			}
			search(idx + 1, new_arr);
		}
		break;
	case 5:
		int new_arr[8][8];
		copy(&arr[0][0], &arr[0][0] + 8 * 8, &new_arr[0][0]);
		for (int k = 0; k < 4; k++) paint(i, j, k, new_arr);
		search(idx + 1, new_arr);
		break;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mapp[i][j];
			if (mapp[i][j] >= 1 && mapp[i][j] < 6) {
				cctv.push_back(make_pair(i, j));
			}
		}
	}
	int arr[8][8];
	copy(&mapp[0][0], &mapp[0][0] + 8 * 8, &arr[0][0]);
	search(0, arr);

	cout << res;
	
	return 0;
}
