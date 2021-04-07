#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int num;
bool used[10] = { false, };
char sign[10] = { '\0', };
char acc[11];
char res[2][11] = { "999999999","0" };

void search(int loc, char n) {
	if (loc == num) {
		if (strcmp(acc, res[0]) < 0) strcpy(res[0], acc);
		if (strcmp(acc, res[1]) > 0) strcpy(res[1], acc);
		return;
	}
	if (sign[loc] == '<') {
		// 오른쪽이 더 큼
		for (char r = '9'; r > n; r--) {
			int idx = r - '0';
			if (!used[idx]) {
				used[idx] = true;
				acc[loc + 1] = r;
				search(loc + 1, r);
				used[idx] = false;
				acc[loc + 1] = '\0';
			}
		}
	}
	else {
		// 왼쪽이 더 큼
		for (char i = '0'; i < n; i++) {
			int idx = i - '0';
			if (!used[idx]) {
				used[idx] = true;
				acc[loc + 1] = i;
				search(loc + 1, i);
				used[idx] = false;
				acc[loc + 1] = '\0';
			}
		}
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> sign[i];
	}
	for (char c = '0'; c <= '9'; c++) {
		memset(used, false, sizeof(used));
		memset(acc, '\0', sizeof(acc));
		acc[0] = c;
		used[c - '0'] = true;
		search(0, c);
	}
	cout << res[1] << '\n';
	cout << res[0] << '\n';
	return 0;
}