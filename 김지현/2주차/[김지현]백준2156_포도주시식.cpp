#include <iostream>
#include <algorithm>
using namespace std;

int mount[10001],cal[10001];
int n;

void solve() {
	cal[0] = 0;
	cal[1] = mount[1];
	cal[2] = mount[1] + mount[2];
	int temp1, temp2;
	for (int i = 3;i <= n;i++) {
		temp1 = max(mount[i] + mount[i - 1] + cal[i - 3], mount[i] + cal[i - 2]);
		temp2 = max(mount[i] + cal[i - 2] , cal[i - 1]);
		cal[i] = max(temp1,temp2);
	}
	cout << cal[n];
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> mount[i];

	solve();

	return 0;
}