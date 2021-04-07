#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 10;
int k;
int op[MAX];
bool visited[MAX];
vector<int> temp;
vector<vector<int>> list;

void solve(int cnt) {
	if (cnt > k ) {
		list.push_back(temp);
		/*for (int i = 0; i <= k; i++) {
			printf("%d", temp[i]);
		}
		printf("\n");*/
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visited[i] == false) {
			if (op[cnt - 1] == 1) {
				if (temp[cnt - 1] < i) {
					temp.push_back(i);
					visited[i] = true;
					solve(cnt + 1);
					temp.pop_back();
					visited[i] = false;
				}
			}
			else {
				if (temp[cnt - 1] > i) {
					temp.push_back(i);
					visited[i] = true;
					solve(cnt + 1);
					temp.pop_back();
					visited[i] = false;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		char temp;
		scanf(" %c", &temp);
		if (temp == '<') {
			op[i] = 1;
		}
		else op[i] = -1;
	}

	for (int i = 0; i < 10; i++) {
		visited[i] = true;
		temp.push_back(i);
		solve(1);
		temp.pop_back();
		visited[i] = false;
	}

	sort(list.begin(), list.end());
	int last = list.size() - 1;
	for (int i = 0; i <= k; i++) {
		printf("%d", list[last][i]);
	}
	printf("\n");
	for (int i = 0; i <= k; i++) {
		printf("%d", list[0][i]);
	}
	printf("\n");
	
	return 0;
}