#include <iostream>
#include<vector>

using namespace std;

int N, K;
vector< vector<int> > v1[1001]; // �� �ε��� �ȿ� �� ��ǥ �����ֵ��� �����ϱ� ���� �������� 
int arr[201][201]={0,};
int S, X, Y;

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};		

void bfs(int k){ // k��° ���̷����� ���� bfs 
	int k_size=v1[k].size();

	vector<int> tv[200*200]; // bfs �� 1cycle ���� ���� ������ ��ǥ�� ������ �ӽ� �迭 
	int cnt=0;
	for(int i=0;i<k_size;i++){
		int x=v1[k][i][0];
		int y=v1[k][i][1];
		
		for(int j=0;j<4;j++){
			int nx=x+dx[j];
			int ny=y+dy[j]; 
		
			if(nx>=1 && nx<=N && ny>=1 && ny<=N){
				if(arr[nx][ny]==0) {
					arr[nx][ny]=k;
					tv[cnt].push_back(nx);
					tv[cnt++].push_back(ny);			
				}
			}					
		}
	}
	v1[k].clear(); // ������ �ִ� k��° ���̷��� �������� ���� -> �ٽ� üũ�� �ʿ� ���� ������ 
	
	for(int i=0;tv[i].empty()!=true;i++){ // ���� ������ ��ǥ�� ��ü 
		v1[k].push_back(tv[i]);
	}
	
	return ;
}

int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){ // bfs�� ���� ���������� �迭ȭ�ϱ� ���� vec Ȱ��
			int t;
			vector<int> v2;
			v2.push_back(i);
			v2.push_back(j);
			
			cin >> t; // t�� ���̷��� ��ȣ�� �ǹ�
			v1[t].push_back(v2); // ���̷��� ��ȣ�� v1�� index�� �ؼ� �� ���̷������� �����ϴ� �� ������ �ֱ� 
			arr[i][j]=t; // ���� ���ϱ� ���� ������ ������ �ʿ���
		}
	}		
	cin >> S >> X >> Y;
		
	for(int s=1;s<=S;s++){
		for(int k=1;k<=K;k++){
			bfs(k);
			
			if(arr[X][Y]!=0){ // ���� ��ǥ�� �߰��� �����Ǹ� ���� 
				cout << arr[X][Y];
				return 0;			
			} 
		}
	}
	cout << arr[X][Y];
	
	return 0;
}
