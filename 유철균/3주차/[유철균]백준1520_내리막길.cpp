#include <iostream>
using namespace std;

int M, N;	// M: �ళ��, N: ������ 
int DP[500][500]={0}; 	// �ش� ĭ���� ������ ���� ���� �����ϴ� �迭 
int dx[4]={1,0,-1,0}; 	// ���� ĭ�� ���� ���̵� 
int dy[4]={0,1,0,-1}; 	// ���� ĭ�� ���� ���̵�
int arr[500][500]; 		// �Է� �迭

int dfs(int x, int y){
	if ((x==M-1) && (y==N-1)) {		// �����ϸ� 1 ���� 
		DP[x][y]=1;
		return 1;
	}
	if(x<0 || x>=M || y<0 || y>=N) return 0; 	// ����� 0 ���� 
	if(DP[x][y]>0 || DP[x][y]==-1) return DP[x][y]; 
	
	for(int i=0;i<4;i++){ 
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if((nx>=0) && (nx<M) && (ny>=0) && (ny<N)) {
			if(arr[nx][ny]<arr[x][y]) {
				if(DP[nx][ny]==-1) continue; 	// ���� ĭ�� �� ���ɼ��� �����Ƿ� ��ŵ 
				int tmp=dfs(nx, ny); 			
				if(tmp!=-1) DP[x][y]+=tmp;		// ���� ĭ�� �� ���ɼ��� ���� -1�̶�� ���ϸ� �ȵ� 
			}
		}						
	}

	if(DP[x][y]==0) DP[x][y]=-1;	// �ش� ĭ���� �� ���ɼ��� ���� ��� ������ ��湮 ���ϱ� ���� -1 ó�� 
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
	if (cnt==-1) cnt=0; 	// ���� �� ���ɼ��� ���� ���ٸ� dfs���� -1�� ���ϵǱ� ������ �� ��쿡�� 0���� �ٲ���  
	cout << cnt;

	return 0;
}
