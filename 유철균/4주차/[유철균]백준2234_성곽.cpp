#include <iostream>

using namespace std;

int M, N;
int arr[50][50];
int visit[50][50]={0};
int arr_area[2500]; // ��� ���� ���̸� �����ϴ� �迭 

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int room_cnt;
int area1, area_t; // area1 : �ִ� �� ���̸� ������ ����, area_t : �ӽ� ���� 
int area2; // �� �㹰���� �� �ִ� �� ���̸� ������ ���� 
int color=1; // ���� �ٸ� �濡�� �ٸ� visit ���� ������ �� ����ϴ� ����  

// ���� ĭ�� �� �� �ִ� ĭ���� �Ǻ��ϴ� �Լ� 
int next(int x, int y, int dir){ 
	int t[4];
	
	if(x>=0 && x<M && y>=0 && y<N){
		int tmp=arr[x][y];
		
		for(int i=3;i>=0;i--){ // 2��Ʈ�� ��ȯ 
			t[i]=tmp%2;
			tmp=tmp/2;
		}
		
		if(t[3]==0 && dir==0) return 1;
		else if(t[2]==0 && dir==1) return 1;
		else if(t[1]==0 && dir==2) return 1;
		else if(t[0]==0 && dir==3) return 1;
		else return 0;
	}
	
	return -1;
}

void dfs(int x, int y){
	visit[x][y]=color;
	area_t++;

	for(int i=0;i<4;i++){
		if(next(x, y, i)==1){
			if(x+dx[i]>=0 && x+dx[i]<M && y+dy[i]>=0 && y+dy[i]<N){
				if(visit[x+dx[i]][y+dy[i]]==0) dfs(x+dx[i],y+dy[i]);
			}
		}
	}
	
	return ;
}

int main(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(visit[i][j]>=1) continue;

			dfs(i, j);

			arr_area[color++]=area_t;
			room_cnt++;

			if(area1<area_t) area1=area_t;			
			area_t=0;
		}
	}

// ����Ž������ ���� ĭ�� �̿� ĭ�� �ٸ� ���� ��� �� �� ���ϱ� 
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			for(int k=0;k<4;k++){
				if(next(i, j, k)==0){
					if(i+dx[k]>=0 && i+dx[k]<M && j+dy[k]>=0 && j+dy[k]<N){
						if(visit[i][j]!=visit[i+dx[k]][j+dy[k]]){												
							int t=arr_area[visit[i][j]]+arr_area[visit[i+dx[k]][j+dy[k]]];
							if(t>area2) area2=t;
						}
					}
				}
			}
		}
	}

  	cout << room_cnt << "\n"; 
  	cout << area1 << "\n"; 
  	cout << area2; 

 	return 0;
}
