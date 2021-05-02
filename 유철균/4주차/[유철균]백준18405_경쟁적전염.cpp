#include <iostream>
#include<vector>

using namespace std;

int N, K;
vector< vector<int> > v1[1001]; // 각 인덱스 안에 들어갈 좌표 순서쌍들을 저장하기 위한 이차벡터 
int arr[201][201]={0,};
int S, X, Y;

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};		

void bfs(int k){ // k번째 바이러스에 대해 bfs 
	int k_size=v1[k].size();

	vector<int> tv[200*200]; // bfs 시 1cycle 동안 새로 생성될 좌표를 저장할 임시 배열 
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
	v1[k].clear(); // 기존에 있던 k번째 바이러스 순서쌍을 없앰 -> 다시 체크할 필요 없기 때문에 
	
	for(int i=0;tv[i].empty()!=true;i++){ // 새로 생성된 좌표로 대체 
		v1[k].push_back(tv[i]);
	}
	
	return ;
}

int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){ // bfs를 위해 순서쌍으로 배열화하기 위한 vec 활용
			int t;
			vector<int> v2;
			v2.push_back(i);
			v2.push_back(j);
			
			cin >> t; // t는 바이러스 번호를 의미
			v1[t].push_back(v2); // 바이러스 번호를 v1의 index로 해서 각 바이러스마다 존재하는 셀 순서쌍 넣기 
			arr[i][j]=t; // 답을 구하기 위해 별도로 맵핑이 필요함
		}
	}		
	cin >> S >> X >> Y;
		
	for(int s=1;s<=S;s++){
		for(int k=1;k<=K;k++){
			bfs(k);
			
			if(arr[X][Y]!=0){ // 구할 좌표가 중간에 생서되면 리턴 
				cout << arr[X][Y];
				return 0;			
			} 
		}
	}
	cout << arr[X][Y];
	
	return 0;
}
