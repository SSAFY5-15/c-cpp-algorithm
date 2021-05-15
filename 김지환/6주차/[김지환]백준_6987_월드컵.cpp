#include <iostream>
#include <vector>
using namespace std;
int sum = 0;
int ST[7] = { 1,2,3,4,5 };
int ARR[7][7] = { 0, };
int f(int cy, int cx) {
	int ret = 0, ans = 0;
	int ny = cy, nx = cx;
	if (cy == 5) {
		if (sum == 0) return 1;
		else return 0;
	}
	else {
		if (cx == 5) {
			ny++;
			nx = ST[ny];
		}
		else nx++;

		//½Â
		if (ARR[cy][0] > 0 && ARR[cx][2] > 0) {

			sum -= 2;
			ARR[cy][0]--; ARR[cx][2]--;

			ret = f(ny, nx);
			if (ret)ans = 1;

			ARR[cy][0]++; ARR[cx][2]++;
			sum += 2;
		}
		//ÆÐ
		if (!ans && ARR[cy][2] > 0 && ARR[cx][0] > 0) {
			sum -= 2;
			ARR[cy][2]--; ARR[cx][0]--;

			ret = f(ny, nx);
			if (ret)ans = 1;

			ARR[cy][2]++; ARR[cx][0]++;
			sum += 2;
		}
		//¹«
		if (!ans && ARR[cy][1] > 0 && ARR[cx][1] > 0) {

			sum -= 2;
			ARR[cy][1]--; ARR[cx][1]--;

			ret = f(ny, nx);
			if (ret)ans = 1;

			ARR[cy][1]++; ARR[cx][1]++;
			sum += 2;
		}
		if (!ans) {
			ret = f(ny, nx);
			if (ret)ans = 1;
		}
	}
	return ans;
}
int main() {
	int i, j, k, ch = 1;
	int ans[5] = { 0, };
	for (i = 0; i < 4; i++) {
		sum = 0; ch = 1;
		for (j = 0; j < 6; j++) {
			int ch2 = 0;
			for (k = 0; k < 3; k++) {
				cin >> ARR[j][k];
				sum += ARR[j][k];
				ch2 += ARR[j][k];
				if (ARR[j][k] >= 6) ch = 0;
			}
			if (ch2 != 5) ch = 0;
		}
		ans[++ans[0]] = (ch) ? f(0, 1) : 0;

	}
	for (i = 1; i <= 4; i++) cout << ans[i] << " ";

}