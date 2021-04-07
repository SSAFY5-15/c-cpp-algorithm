#include <iostream>
#include <vector>
using namespace std;
int N, arr[13] = { 0, }, tr[13] = { 0, }, visited[13] = { 0, };
vector <int> v;
void c(int n, int l) {
	int i, j;
	if (n == 6) {
		for (i = 0; i < v.size(); i++) cout << v.at(i) << " ";
		cout << endl;
		return;
	}
	for (i = l; i < N; i++) {
		v.push_back(arr[i]);
		c(n + 1, i + 1);
		v.pop_back();
	}
}
int main() {
	int i, j;
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (i = 0; i < N; i++) cin >> arr[i];
		c(0, 0);
		cout << "\n";
	}
}