#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
const int MAX = 25;
int n;
int arr[MAX][MAX];
bool visited[MAX];
int minn = 987654321;

void cal() {
	int a_team = 0, b_team = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i] == true && visited[j] == true && i!=j) {
				a_team += arr[i][j];
			}
			else if(visited[i]==false && visited[j] == false) {
				b_team += arr[i][j];
			}
		}
	}

	int temp = abs(a_team - b_team);
	if (temp < minn) minn = temp;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	vector<bool> binary(n);
	fill(binary.end() - (n / 2), binary.end(),true);
	do {
		for (int i = 0; i < n; i++) {
			if (binary[i] == true) {
				visited[i] = true;
			}
			else {
				visited[i] = false;
			}
		}
		cal();
	} while (next_permutation(binary.begin(), binary.end()));

	printf("%d\n", minn);

	return 0;
}