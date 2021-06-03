#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<int> s;
int hope[100001], team[100001];
bool checked[100001], visited[100001];
int N, t, cnt;

void init() {
	int size = N + 1;
	for (int i = 1; i < size; i++) {
		team[i] = -1;
		checked[i] = false;
		visited[i] = false;
	}
	t = 1;
	cnt = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		init();

		for (int i = 1; i <= N; i++)    cin >> hope[i];
		
		for (int i = 1; i <= N; i++) {
			if (!checked[i]) {
				int tmp = i;
				while (1) {
					// check loop
					if (checked[tmp]) {
						int origin = tmp;
						while (1) {
							tmp = s.top();
							s.pop();
							team[tmp] = t;
							if (tmp == origin)    break;
						}
						while (!s.empty()) {
							tmp = s.top();
							s.pop();
							team[tmp] = 0;
						}
						t++;
						break;
					}

					// update tmp
					checked[tmp] = true;
					s.push(tmp);
					tmp = hope[tmp];
					if (team[tmp] != -1) {
						while (!s.empty()) {
							tmp = s.top();
							s.pop();
							team[tmp] = 0;
						}
						break;
					}
				}
			}
			if (team[i] == 0)    cnt++;
		}

		cout << cnt << '\n';
	}
	return 0;
}