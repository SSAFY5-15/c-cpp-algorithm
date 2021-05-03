#include <iostream>
using namespace std;
int N, i,cur, pre, mx=1e9, sum=0;
int main() {
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> cur;
		if (i == 0) {
			pre = cur; mx = cur;
		}
		else {
			if (pre < 0) pre = 0;
			if (mx < pre + cur) mx = pre + cur;
			pre += cur;
		}
		//cout << pre << " ";
	}
	cout << mx << endl;
}