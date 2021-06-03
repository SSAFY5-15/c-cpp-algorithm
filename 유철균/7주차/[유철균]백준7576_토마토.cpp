#include <iostream>
#include <queue> 

using namespace std;

int N,M;
int arr[1000][1000];
queue<pair<int, int> > q; // 익은 토마토 좌표 저장할 큐
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int day; // 결과값
int fullcheck=1; // 익지 않은 토마토 존재여부 체크하는 변수
 
int bfs(){ // while문 한바퀴마다 하루가 지나 토마토 밭이 변함
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
					arr[nx][ny]=1; // 토마토 익히기					
					q.push(make_pair(nx, ny)); // 추가
				}				
			}
		}
		day++;
	}

	for(int i=0;i<N;i++){ // 안익은 토마토가 있는지 확인
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
