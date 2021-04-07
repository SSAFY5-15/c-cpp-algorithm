#include <iostream>
#include <cstring>

using namespace std;

int visited[10], N, flag_max, flag_min;
char sign[9], output_max[11], output_min[11];

void init() {
	memset(sign, 0, sizeof(char) * 9);
	memset(output_max, 0, sizeof(char) * 11);
	memset(output_min, 0, sizeof(char) * 11);
	memset(visited, 0, sizeof(int) * 10);
}

int compare_number(char eq, char num1, char num2) {
	if (eq == '>') {
		if (num1 > num2)    return 1;
		return 0;
	}
	else if (eq == '<') {
		if (num1 < num2)    return 1;
		return 0;
	}
	else    return -1;
}

void find_min(int k) {
	if (k == N + 1) {
		flag_min = 1;
		output_min[N + 1] = '\0';
		cout << output_min << endl;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (flag_min == 0 && visited[i] == 0) {
				if (k == 0) {
					visited[i] = 1;
					output_min[k] = '0' + i;
					find_min(k + 1);
					visited[i] = 0;
				}
				else if (compare_number(sign[k - 1], (int)(output_min[k - 1] - '0'), i) == 1) {
					visited[i] = 1;
					output_min[k] = '0' + i;
					find_min(k + 1);
					visited[i] = 0;
				}
			}
		}
	}
}

void find_max(int k) {
	if (k == N + 1) {
		flag_max = 1;
		output_max[N + 1] = '\0';
		cout << output_max << endl;
	}
	else {
		for (int i = 9; i >= 0; i--) {
			if (flag_max == 0 && visited[i] == 0) {
				if (k == 0) {
					visited[i] = 1;
					output_max[k] = '0' + i;
					find_max(k + 1);
					visited[i] = 0;
				}
				else if (compare_number(sign[k - 1], (int)(output_max[k - 1] - '0'), i) == 1) {
					visited[i] = 1;
					output_max[k] = '0' + i;
					find_max(k + 1);
					visited[i] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)    cin >> sign[i];

	find_max(0);
	find_min(0);

	return 0;
}