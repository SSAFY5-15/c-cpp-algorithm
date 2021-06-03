#include <iostream>
#include <string.h>
#define INF 1000000000
#define n 125

using namespace std;

int N;
int arr[n][n];

int d[n][n]; // �ּ� ������ 
int v[n][n]; // �湮 ó�� 
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int cnt=1; // problem number
int pnt[2]; // ���� �� �ּ��� ��ǥ ����

void getSmallIndex(){ // ���� ���� ���� ���� ������ ��ǥ ����
	int min=INF;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(min>d[i][j] && v[i][j]==0){
				min=d[i][j];
				pnt[0]=i;
				pnt[1]=j;
			}
		}
	}
	
	return ;
}

void daijkstra(){
	for(int i=0;i<N*N-1;i++){
		getSmallIndex(); // ���� ���� ������ ��ǥ �ޱ�
		v[pnt[0]][pnt[1]]=1; // �湮 ó��
		
		for(int j=0;j<4;j++){
			int nx=pnt[0]+dx[j];
			int ny=pnt[1]+dy[j];
			
			if(nx>=0 && nx<N && ny>=0 && ny<N){ // �ּҰ� �ٲ�ġ�� 
				if(d[nx][ny]>d[pnt[0]][pnt[1]]+arr[nx][ny]){
					d[nx][ny]=d[pnt[0]][pnt[1]]+arr[nx][ny];
				}
			}
		}
	}

	return ;
}

void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			d[i][j]=INF;
		}
	}
	
	for(int i=0;i<N;i++){
		memset(v[i], 0, sizeof(v[i]));
	}	
	
	d[0][0]=arr[0][0];
	v[0][0]=1;
	
	d[1][0]=arr[0][0]+arr[1][0];	
	d[0][1]=arr[0][0]+arr[0][1];
	
	return ;	
}

int main(){
	while(1){
		cin >> N;
		if(N==0) break;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> arr[i][j];
			}
		}
		
		init();
		daijkstra();
		cout << "Problem " << cnt << ": " << d[N-1][N-1] << "\n";
		cnt++;
	}

	return 0;
}
