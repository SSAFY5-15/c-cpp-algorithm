#include <iostream>
#include <queue> 

using namespace std;

int N,M;
int arr[1000][1000];
queue<pair<int, int> > q; // ���� �丶�� ��ǥ ������ ť
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int day; // �����
int fullcheck=1; // ���� ���� �丶�� ���翩�� üũ�ϴ� ����
 
int bfs(){ // while�� �ѹ������� �Ϸ簡 ���� �丶�� ���� ����
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			pair<int, int> tmp=q.front();
			q.pop();
			
			for(int j=0;j<4;j++){
				int nx=tmp.first+dx[j];
				int ny=tmp.second+dy[j];
				
				if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
				if(arr[nx][ny]==0) {
					arr[nx][ny]=1; // �丶�� ������					
					q.push(make_pair(nx, ny)); // �߰�
				}				
			}
		}
		day++;
	}

	for(int i=0;i<N;i++){ // ������ �丶�䰡 �ִ��� Ȯ��
		for(int j=0;j<M;j++){
			if(arr[i][j]==0) return -1;
		}
	}
	return day; 
}

int main(){
	cin >> M >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
			if(arr[i][j]==1) q.push({i, j});
			if(arr[i][j]==0) fullcheck=0;
		}
	}
	if(fullcheck==1) {
		cout << 0;
		return 0;	
	}
	
	int ret = bfs();
	if(ret==-1) cout << -1;
	else cout << ret-1;
	
	return 0;
} 
