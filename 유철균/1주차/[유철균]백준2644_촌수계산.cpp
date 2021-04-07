#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
vector<int> vec[200]; // int�� ���� ����� 
int visited[100],n,r1,r2, m; 
int cnt = 0;
bool v = 0;

void BFS(int start) {
	queue<int> q;
	visited[start] = 1;
	q.push(start); // ������ index�� �ֱ�
	
	int qsize;
	int qx_size;
	while (!q.empty()) {
		qsize=q.size();
		for (int i = 0; i < qsize; i++) {
			int t1 = q.front(); // 0 index �� ��ȯ 
			q.pop(); // 0 index �� ����  
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
	cin >> n>>r1>>r2>>m; // ����, ���ͽ� ���� �Է����� �Ѿ 

	for (int i = 0; i < m; i++) {
		int  x, y;
		cin >> x >> y;
		// ��� ��ȣ�� index�� �ϰ� 1�� ������ ����� ��ȣ �߰� -> �ߺ���� 
		vec[x].push_back(y); 
		vec[y].push_back(x);
	}

	BFS(r1);
	if (v == 0) cout << -1;
	else cout << cnt;
}


