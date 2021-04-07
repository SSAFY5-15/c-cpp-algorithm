#include <iostream>

using namespace std;

int k;
int arr[13] = { 0 };
int lotto[13] = { 0 };

void bt(int a,int d) {
	if (d == 6) {
		for (int i = 0;i < 6;i++) {
			cout << lotto[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = a;i < k;i++) {
		lotto[d] = arr[i];
		bt(i + 1, d + 1);//Àç±Í·Î depth¸¦ ´Ã·ÁÁÖ¸é¼­ 6ÀÌµÇ¸é Å»Ãâ
	}
}

int main() {
	while (1) {
		for (int i = 0;i < 13;i++) arr[i] = 0;
		cin >> k;
		if (k == 0) break;
		for (int i = 0;i < k;i++) cin >> arr[i];

		bt(0,0);
		cout << endl;
	}
	return 0;
}