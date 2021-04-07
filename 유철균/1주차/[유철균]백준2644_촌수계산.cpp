#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
vector<int> vec[200]; // int형 벡터 만들기 
int visited[100],n,r1,r2, m; 
int cnt = 0;
bool v = 0;

void BFS(int start) {
	queue<int> q;
	visited[start] = 1;
	q.push(start); // 마지막 index에 넣기
	
	int qsize;
	int qx_size;
	while (!q.empty()) {
		qsize=q.size();
		for (int i = 0; i < qsize; i++) {
			int t1 = q.front(); // 0 index 값 반환 
			q.pop(); // 0 index 값 삭제  
			if (t1 == r2) {
				v = 1;
				return;  
			}
			
			qx_size=vec[t1].size();
			for (int i = 0; i < qx_size; i++) { 
				int t2 = vec[t1][i]; 
				if (!visited[t2]) {
					visited[t2]=1;
					q.push(t2);
				}
			}
		}
		cnt++;
	}
}

int main() {	
	cin >> n>>r1>>r2>>m; // 공백, 엔터시 다음 입력으로 넘어감 

	for (int i = 0; i < m; i++) {
		int  x, y;
		cin >> x >> y;
		// 사람 번호를 index로 하고 1촌 관계인 사람들 번호 추가 -> 중복허용 
		vec[x].push_back(y); 
		vec[y].push_back(x);
	}

	BFS(r1);
	if (v == 0) cout << -1;
	else cout << cnt;
}


