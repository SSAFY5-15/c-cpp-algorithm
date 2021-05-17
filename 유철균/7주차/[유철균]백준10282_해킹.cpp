#include <iostream>
#include <vector>
#include <string.h>
#define INF 100000000

using namespace std;

int tc;
int n, d, c; // 컴개수, 의존성개수, 해킹된 컴터 번호 

vector<pair<int, int> > vec;
vector<vector<pair<int, int> > > lst(10001,vec);
int v[10001]; // 방문여부
int acc[10001]; // 누적값 저장하는 배열 
int cnt; // 감염되는 com 개수

int getSmallNode(){ // 가장 작은 누적 시간을 가지는 com 번호 구하기 
	int min=INF;
	int node=0;
	for(int i=1;i<10001;i++){
		if(v[i]==0 && min>acc[i]){
			min=acc[i];
			node=i;
		}
	}
	if(node==0) return -1;
	return node;
}

int dijkstra(){
	int ans=0;
	
	while(1){
		int node=getSmallNode(); // 모든 노드 중 누적값 최소인 node에 방문 표시 
		if(node==-1) { // 더 이상 방문할 com이 없다면 
			for(int i=1;i<=n;i++){
				if(acc[i]!=INF && ans<acc[i]){
					ans=acc[i];
				}
			}
			break;
		}
		
		v[node]=++cnt;
		int size=lst[node].size();
		for(int j=0;j<size;j++){ // node와 연결된 다음 nnode에 대해 누적값 최신화
			int nnode=lst[node][j].first;
			if(acc[nnode]>acc[node]+lst[node][j].second){
				acc[nnode]=acc[node]+lst[node][j].second;
			}
		}
	}
	
	return ans;
} 

void init(){
	cnt=0;
	memset(v, 0, sizeof(v));
	for(int i=0;i<10001;i++){
		acc[i]=INF;
	}
	lst.clear();
	lst.assign(10001, vec);
	
	return ; 
}

int main(){
	cin >> tc;
	while(tc--){
		init();
		cin >> n >> d >> c;
		for(int i=0;i<d;i++){
			int x, y, t;
			cin >> y >> x >> t;
			lst[x].push_back({y, t});
		}
		
		int size=lst[c].size();
		for(int i=0;i<size;i++){
			acc[lst[c][i].first]=lst[c][i].second; // 누적합 배열에 넣기
		}
		v[c]=++cnt;
		int ans=dijkstra();
		
		cout << cnt << " " << ans << "\n";
	}
	
	return 0;
}
