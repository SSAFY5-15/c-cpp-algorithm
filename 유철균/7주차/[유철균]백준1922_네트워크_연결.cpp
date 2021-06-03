#include <iostream>
#include <vector>

using namespace std;
int N, M; //노드 수, 간선 수

vector<pair<int, int> > nodes; // 현재 존재하는 노드들에 대해 (새로운 연결노드, 비용)을 저장하는 벡터 
vector<pair<int, int> > p;
vector<vector<pair<int, int> > > neight(1001, p); // index=자신노드, pair<이웃노드, 비용>
int v[10001]={0}; // 방문 
int ans; // 결과값

int minValueIndex(){ // nodes에서 최소 비용을 가지는 순서쌍의 index 찾기 
	int min=10001;
	int idx;
	int tmp=nodes.size();
	for(int i=0;i<tmp;i++){
		if(min>nodes[i].second && v[nodes[i].first]==0){
			idx=i;
			min=nodes[i].second;
		}
	}
	
	return idx;
} 

void solve(){ // 가장 적은 비용의 연결노드를 추가하는 걸 반복해 최소 비용 계산
	int tmp=neight[1].size();
	for(int i=0;i<tmp;i++){ // 1번 노드 이웃 배열 
		nodes.push_back(neight[1][i]);
	}
	
	for(int i=0;i<N-1;i++){
		int idx=minValueIndex();  
		int node=nodes[idx].first; // node는 새로 연결할 노드 
		v[node]=1;
		ans+=nodes[idx].second;
		
		// 추가된 노드의 연결노드를 nodes에 추가하기
		int tmp=neight[node].size(); 
		for(int i=0;i<tmp;i++){
			if(v[neight[node][i].first]==0) nodes.push_back(neight[node][i]);	
		}
	}
	 
	return ;
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int p1, p2, value;
		cin >> p1 >> p2 >> value;
		if(p1==p2) continue;

		neight[p1].push_back({p2, value});
		neight[p2].push_back({p1, value});
	}
	
	v[1]=1;
	solve();
	cout << ans;
	return 0;
}
