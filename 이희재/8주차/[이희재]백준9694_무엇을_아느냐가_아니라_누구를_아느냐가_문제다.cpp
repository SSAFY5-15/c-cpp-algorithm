#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 100
using namespace std;
vector<pair<int, int>> familiar[20];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, M, Min;
int dist[20];
int pre[20];


int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	
	for(int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		// Initialize
		Min = 0;
		dist[0] = 0;
		pre[0] = -1;
		familiar[0].clear();
		for (int i = 1; i < M; i++) {
			dist[i] = INF;
			pre[i] = -1;
			familiar[i].clear();
		}
		Min = INF;

		while (N--) {
			int a, b, d;
			cin >> a >> b >> d;
			familiar[a].push_back({ d, b });
			familiar[b].push_back({ d, a });
		}
		
		int size_zero = familiar[0].size();
		for (int i = 0; i < size_zero; i++) {
			dist[familiar[0][i].second] = familiar[0][i].first;
			pre[familiar[0][i].second] = 0;
			pq.push( familiar[0][i] );
		}

		while (!pq.empty()) {
			int tmp_dist = pq.top().first;
			int tmp_node = pq.top().second;
			pq.pop();
			int tmp_size = familiar[tmp_node].size();

			for (int i = 0; i < tmp_size; i++) {
				int next_dist = tmp_dist + familiar[tmp_node][i].first;
				int next_node = familiar[tmp_node][i].second;
				if (next_dist < dist[next_node]) {
					dist[next_node] = next_dist;
					pre[next_node] = tmp_node;
					pq.push({ next_dist, next_node });
				}
			}
		}

		cout << "Case #" << tc << ":";
		if (dist[M-1] == INF)    cout << "-1";
		else {
			stack<int> s;
			int tmp = M-1;
			s.push(M-1);
			while (1) {
				tmp = pre[tmp];
				s.push(tmp);
				if (tmp == 0)    break;
			}
			while (!s.empty()) {
				cout << " " << s.top();
				s.pop();
			}
		}
		cout << "\n";
	}
	return 0;
}