#include <iostream>
#include <queue>
using namespace std;
vector<pair<int, int>> v[10001];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
bool infected[10001];
int sec, cnt;

void init() {
	for (int i = 0; i < 10001; i++) {
		v[i].clear();
		infected[i] = false;
	}
	while (!pq.empty())    pq.pop();
	sec = 0;
	cnt = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc;
	for (int test_case = 0; test_case < tc; test_case++) {
		init();

		int n, d, c;
		cin >> n >> d >> c;
		for (int dependency_i = 0; dependency_i < d; dependency_i++) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ s, a });
		}

		pq.push({ 0, c });

		while (!pq.empty()) {
			int next_sec = pq.top().first;
			int next_computer = pq.top().second;
			if (infected[next_computer] == true) {
				pq.pop();
				continue;
			}
			if (sec == next_sec ) {
				pq.pop();
				infected[next_computer] = true;
				cnt++;
				int next_size = v[next_computer].size();
				for (int i = 0; i < next_size; i++) {
					int tmp_sec = v[next_computer][i].first + sec;
					int tmp_computer = v[next_computer][i].second;
					if (infected[tmp_computer] == true)    continue;
					pq.push({ tmp_sec, tmp_computer });
				}
			}
			else    sec = next_sec;
		}

		cout << cnt << " " << sec << '\n';
	}
	return 0;
}