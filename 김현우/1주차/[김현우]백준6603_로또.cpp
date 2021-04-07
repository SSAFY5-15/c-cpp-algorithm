#include <iostream>

using namespace std;

int B[50];
int A[6];
int T;

void DFS(int dep,int st) {
	if (dep == 6) {
		for (int j = 0; j < 6; j++) cout << A[j] <<" ";
		cout << endl;
		return;
	}
	else {
		for (int i = st ; i < T; i++) {
			A[dep++] = B[i];
			DFS(dep, i + 1);
			dep--;
		}
	}
}

int main() {
	cin >> T;
	while (T) {		
		for (int i = 0; i < T; i++) cin >> B[i];
		DFS(0, 0);
		cout << endl;
		cin >> T;
	}
	return 0;
}