#include <iostream>
#define MAX(a,b) (((a) > (b)) ? (a):(b))
using namespace std;

int B[10001];
int DP[10001];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin>>B[i];
	}
	DP[0] = B[0];
	DP[1] = B[0] + B[1];
	DP[2] = MAX(MAX(B[0] + B[2], B[1] + B[2]), DP[1]);
	
	for (int n = 3; n < N; n++) {
		DP[n] = MAX(MAX(DP[n - 2] + B[n], DP[n - 3] + B[n-1] + B[n]), DP[n - 1]);
	}
	cout << DP[N - 1] << endl;
	return 0;
}