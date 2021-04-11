#include<iostream>

using namespace std;

int N, M;
int arr[8][8];
int perm_lst[1000000][8]={-1,};
int a=0;

// 모든 cctv에 대해 가능한 조합  
void perm(int count, int cctv, int *t){
	if(count==cctv){
		for(int i=0;i<cctv;i++){
			perm_lst[a][i]=t[i];
		}
		a++;
		return ;
	}
	
	for(int i=0;i<4;i++){
		t[count]=i;
		perm(count+1, cctv, t);
	}
	return ;
}

// 0부터 3까지 순서대로 오른쪽, 아래, 왼쪽, 위 방향으로 감시한 cell -1 처리하기 
void direction(int n, int m, int dir){
	if(dir==0){
		for(int i=m;i<M;i++){
			if(arr[n][i]==6) break;
			if(arr[n][i]==0) arr[n][i]=-1;
		}
	}
	else if(dir==1){
		for(int i=n;i<N;i++){
			if(arr[i][m]==6) break;
			if(arr[i][m]==0) arr[i][m]=-1;
		}
	}
	else if(dir==2){
		for(int i=m;i>=0;i--){
			if(arr[n][i]==6) break;
			if(arr[n][i]==0) arr[n][i]=-1;
		}
	}
	else{
		for(int i=n;i>=0;i--){
			if(arr[i][m]==6) break;
			if(arr[i][m]==0) arr[i][m]=-1;
		}
	}
	return ;
}

// 1~5까지 유형의 cctv 감시 함수 
void cctv1(int n, int m, int dir){
	if(dir==0) direction(n, m, 0);
	else if(dir==1) direction(n, m, 1);
	else if(dir==2) direction(n, m, 2);
	else direction(n, m, 3);
	return ;
}

void cctv2(int n, int m, int dir){
	if(dir==0) {
		direction(n, m, 0);
		direction(n, m, 2);
	}
	else if (dir==1) {
		direction(n, m, 1);
		direction(n, m, 3);
	}
	return ;
}

void cctv3(int n, int m, int dir){
	if(dir==0) {
		direction(n, m, 0);
		direction(n, m, 1);
	}
	else if(dir==1) {
		direction(n, m, 1);
		direction(n, m, 2);
	}
	else if(dir==2) {
		direction(n, m, 2);
		direction(n, m, 3);
	}
	else if (dir==3) {
		direction(n, m, 3);
		direction(n, m, 0);
	}
	return ;
}

void cctv4(int n, int m, int dir){
	if(dir==0) {
		direction(n, m, 0);
		direction(n, m, 1);
		direction(n, m, 2);
	}
	else if(dir==1) {
		direction(n, m, 1);
		direction(n, m, 2);
		direction(n, m, 3);
	}
	else if(dir==2) {
		direction(n, m, 2);
		direction(n, m, 3);
		direction(n, m, 0);
	}
	else if (dir==3) {
		direction(n, m, 3);
		direction(n, m, 0);
		direction(n, m, 1);
	}
	return ;
}

void cctv5(int n, int m){
	direction(n, m, 0);
	direction(n, m, 1);
	direction(n, m, 2);
	direction(n, m, 3);
	
	return ;
}

// main에서 하나의 cctv 조합 경우를 고려한 후 리셋하기 위한 init함수 
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]==-1) arr[i][j]=0;
		}
	}	
}

int main(){

	cin >> N >> M;
	int ret=M*N;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
		}
	}
		
	// cnt : cctv 개수
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]!=0 && arr[i][j]!=6) cnt++;
		}
	}
	
	// 가능한 모든 조합을 perm_lst에 행별로 담기
	int t[cnt];
	perm(0, cnt, t);
	
	int x=0;
	while(perm_lst[x][0]!=-1){  // 모든 cctv 조합을 고려하기 위한 while뮨 
		int y=0;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(arr[i][j]==1) cctv1(i, j, perm_lst[x][y++]) ;
				else if(arr[i][j]==2) cctv2(i, j, perm_lst[x][y++]) ;
				else if(arr[i][j]==3) cctv3(i, j, perm_lst[x][y++]) ;
				else if(arr[i][j]==4) cctv4(i, j, perm_lst[x][y++]) ;
				else if(arr[i][j]==5) {
					cctv5(i, j) ;
					y++;
				}
			}
		}
		
		// 각 조합에서의 사각지대 개수 : t_ret 
		int t_ret=0;
		
	    for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(arr[i][j]==0) t_ret++;
			}
		}		
		
		if(t_ret<ret) ret=t_ret;
		
		init();  // 초기화 
		x++;
	}

	// 이 반례 때문에 무진장 걸림...ㅠ
	// cctv가 없을 때 while문 자체를 타지 않기 때문에
	// 179번 코드부분이 실행되지 않아 사각지대가 전체개수로 나옴
	// 그래서 밑에 cctv가 하나도 없을 때 경우를 고려해줌  
	int flag=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]!=6 && arr[i][j]!=0) {
				flag=1;	
			}			
			if(i==N-1 && j==M-1 && flag==0) {
				int t_ret=0;
				for(int i=0;i<N;i++){
					for(int j=0;j<M;j++){
						if(arr[i][j]==0) t_ret++;
					}
				}
	
				cout << t_ret;
				return 0;
			}
		}
	}
	
	cout << ret;
	return 0;
}





