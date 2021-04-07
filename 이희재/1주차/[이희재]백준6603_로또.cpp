#include <iostream>
#include <cstring>

using namespace std;

int arr[12], selected[12];
int N, flag;

void init() {
	memset(arr, 0, sizeof(int) * 12);
	memset(selected, 0, sizeof(int) * 12);
}

void select(int order, int k) {
	if (k == 6) {
		for (int i = 0; i < N; i++)
			if (selected[i] == 1)
				cout << arr[i] << " ";
		cout << endl;
	}
	else if (N - order >= 6 - k){
		for (int i = order; i < N; i++) {
			selected[i] = 1;
			select(i+1, k + 1);
			selected[i] = 0;
		}
	}
}

int main() {
	flag = 0;

	while (1) {
		cin >> N;
		if (N < 7)    break;
		else {
			init();
			if (flag == 0)    flag = 1;
			else    cout << endl;
			for (int i = 0; i < N; i++)    cin >> arr[i];
			select(0, 0);
		}

	}
	return 0;
}