#include<iostream>

using namespace std;

int N, M;
int arr[8][8];
int perm_lst[1000000][8]={-1,};
int a=0;

// ��� cctv�� ���� ������ ����  
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

// 0���� 3���� ������� ������, �Ʒ�, ����, �� �������� ������ cell -1 ó���ϱ� 
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

// 1~5���� ������ cctv ���� �Լ� 
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

// main���� �ϳ��� cctv ���� ��츦 ����� �� �����ϱ� ���� init�Լ� 
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
		
	// cnt : cctv ����
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]!=0 && arr[i][j]!=6) cnt++;
		}
	}
	
	// ������ ��� ������ perm_lst�� �ະ�� ���
	int t[cnt];
	perm(0, cnt, t);
	
	int x=0;
	while(perm_lst[x][0]!=-1){  // ��� cctv ������ ����ϱ� ���� while�� 
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
		
		// �� ���տ����� �簢���� ���� : t_ret 
		int t_ret=0;
		
	    for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(arr[i][j]==0) t_ret++;
			}
		}		
		
		if(t_ret<ret) ret=t_ret;
		
		init();  // �ʱ�ȭ 
		x++;
	}

	// �� �ݷ� ������ ������ �ɸ�...��
	// cctv�� ���� �� while�� ��ü�� Ÿ�� �ʱ� ������
	// 179�� �ڵ�κ��� ������� �ʾ� �簢���밡 ��ü������ ����
	// �׷��� �ؿ� cctv�� �ϳ��� ���� �� ��츦 �������  
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





