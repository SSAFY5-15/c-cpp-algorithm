#include <iostream>
#include <cstring>
using namespace std;

int players[20][20];
int team[20];
int N, minimum;

void init() {
	for (int i = 0; i < 20; i++)
		memset(players[i], 0, sizeof(int) * 20);
	memset(team, 0, sizeof(int) * 20);
	minimum = 1e9;
}

// 2 팀에 속할 사람을 선택한다. k 는 해당 순간에 선출된 2팀의 인원을 의미한다.
// k 가 전체 인원의 반이 되면 해당 팀 구성에서 나타나는 시너지를 계산하여
// 해당 값이 최솟값인지 결정한다.
void dfs(int k, int index) {
	if (k == N / 2) {
		int cur = 0;
		int synergy_one = 0;
		int synergy_two = 0;
		for (int i = 0; i < N; i++) {
			if (team[i] == 0) {
				for (int j = 0; j < N; j++) {
					if (i != j && team[j] == 0) {
						synergy_one += players[i][j];
					}
				}
			}
			else {
				for (int j = 0; j < N; j++){
					if (i != j && team[j] == 1) {
						synergy_two += players[i][j];
					}
				}
			}
		}
		if (synergy_one > synergy_two)    cur = synergy_one - synergy_two;
		else    cur = synergy_two - synergy_one;
		if (cur < minimum)    minimum = cur;
		return;
	}
	else {
		for (int i = index; i < N; i++) {
			if (team[i] != 1) {
				team[i] = 1;
				dfs(k + 1, i + 1);
				team[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	init();

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> players[i][j];
	
	dfs(0, 0);

	cout << minimum << '\n';

	return 0;
}