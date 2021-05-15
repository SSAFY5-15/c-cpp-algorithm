#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define R 111111
vector<pair<int, int>> G[R]; //그래프
struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>,vector<pair<int,int>>, cmp> pq;
int dist[R] = { 0, }, check[R] = { 0, };
int V, E;
int main() {
	freopen("input.txt", "r", stdin);
	int i, j, ret = 0;
	cin >> V >> E;

	int tmp1, tmp2, tmp3;
	for (int i = 0; i < E; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		G[tmp1].push_back(make_pair(tmp2, tmp3));
		G[tmp2].push_back(make_pair(tmp1, tmp3));
	}

	for (i = 1; i <= V; i++) {
		check[i] = false;
		dist[i] = 1e9;
	}
	
	int w = 0, cnt = 0;
	pair<int, int> cur;
	pq.push({ 1,0 });
	dist[1] = 0;
	for (w = 1; w <= V; w++) {
		cur = { -1,-1 };

		//탐색할 노드를 선택. 방문한적 없는 노드를 찾으면 멈춤.
		while (!pq.empty()) {
			cur = pq.top(); pq.pop();
			if (check[cur.first]) continue;
			else {
				check[cur.first] = 1;
				break;
			}
		}

		//선택한 노드를 기준으로 가중치 갱신.
		for (auto &i : G[cur.first]) {
			if (check[i.first]) continue;
			if (i.second < dist[i.first]) dist[i.first] = i.second;
			pq.push(i);
		}
	}
	for (auto&d : dist) ret += d;
	cout << ret << endl;
}

/*
4 4
1 2 -1
2 3 -1
3 4 -1
4 1 -1

4 4
1 2 -1
3 4 -1
2 3 -1
3 1 -1
*/