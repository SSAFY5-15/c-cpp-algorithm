
#include <iostream>
using namespace std;
int arr[10001] = { 0, }, mem[3][10001] = { 0, };
int N;
int f(int s, int s2) {
	int ret, mx = -1e9, cur = (s2 == 0) ? 0 : arr[s];
	if (s == N + 1) return 0;
	if (s != 0 && mem[s2][s] != -1e9) return mem[s2][s];
	//만약 다음께 연속 세번째가 아니라면
	if (s2 != 2) {
		ret = cur + f(s + 1, s2 + 1);
		if (mx < ret) mx = ret;
	}
	ret = cur + f(s + 1, 0);
	if (mx < ret) mx = ret;

	//세번째라면
	mem[s2][s] = mx;
	return mx;
}
int main() {
	int i, j;
	cin >> N;

	//초기화
	for (i = 1; i <= N; i++) for (j = 0; j < 3; j++) mem[j][i] = -1e9;
	for (i = 1; i <= N; i++) cin >> arr[i];
	cout << f(0, 0) << endl;
}

/*
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int arr[10001] = { 0, }, mem[3][10001] = { 0,};
int N;
int f(int s,int s2) {
	int ret, mx = -1e9, cur = (s2 ==0 )? 0 : arr[s];
	if (s == N+1) return 0;
	if (mem[s2][s] != -1e9) return mem[s2][s];

	//상태가 연속 2번째가 아닌 경우, 다음번째 순서 생성.
	if (s2 != 2) {
		ret = cur + f(s + 1, s2 + 1);
		if (mx < ret) mx = ret;
	}
	ret = cur +f(s + 1, 0);
	if (mx < ret) mx = ret;


	mem[s2][s] = mx;
	return mx;
}
int main() {
	int i, j;
	cin >> N;

	//초기화
	for(i = 1; i <= N; i++) for(j = 0; j < 3; j++) mem[j][i] = -1e9;
	for(i = 1; i <= N; i++) cin >> arr[i];
	cout << f(0, 0) << endl;
}
*/