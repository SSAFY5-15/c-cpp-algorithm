#include <iostream>
using namespace std;

int M, N;	// M: 행개수, N: 열개수 
int DP[500][500]={0}; 	// 해당 칸에서 가능한 길의 개수 저장하는 배열 
int dx[4]={1,0,-1,0}; 	// 다음 칸에 더할 행이동 
int dy[4]={0,1,0,-1}; 	// 다음 칸에 더할 열이동
int arr[500][500]; 		// 입력 배열

int dfs(int x, int y){
	if ((x==M-1) && (y==N-1)) {		// 도착하면 1 리턴 
		DP[x][y]=1;
		return 1;
	}
	if(x<0 || x>=M || y<0 || y>=N) return 0; 	// 벗어나면 0 리턴 
	if(DP[x][y]>0 || DP[x][y]==-1) return DP[x][y]; 
	
	for(int i=0;i<4;i++){ 
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if((nx>=0) && (nx<M) && (ny>=0) && (ny<N)) {
			if(arr[nx][ny]<arr[x][y]) {
				if(DP[nx][ny]==-1) continue; 	// 다음 칸이 길 가능성이 없으므로 스킵 
				int tmp=dfs(nx, ny); 			
				if(tmp!=-1) DP[x][y]+=tmp;		// 다음 칸이 길 가능성이 없어 -1이라면 더하면 안됨 
			}
		}						
	}

	if(DP[x][y]==0) DP[x][y]=-1;	// 해당 칸에서 길 가능성이 없을 경우 다음에 재방문 안하기 위한 -1 처리 
	return DP[x][y];
}

int main(){
	cin >> M >> N;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
		}
	}
	
	int cnt=dfs(0,0);
	if (cnt==-1) cnt=0; 	// 만약 길 가능성이 전혀 없다면 dfs에서 -1로 리턴되기 때문에 이 경우에만 0으로 바꿔줌  
	cout << cnt;

	return 0;
}
