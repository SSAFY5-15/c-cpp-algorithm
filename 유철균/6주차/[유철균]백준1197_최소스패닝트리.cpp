#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int V, E; // ����, ���� ����

vector<pair<int, int> > p;
vector<vector<pair<int, int> > > lst(10001, p); // ���� ��� ǥ���ϴ� ����Ʈ 
int v[10001]={0}; // �湮 

vector<pair<int, int> > nodes;
int ans;

int minValueIndex(){
	int min=MAX;
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

void solve(){
	int tmp=lst[1].size();
	for(int i=0;i<tmp;i++){ // 1�� ��� �̿� �迭 
		nodes.push_back(lst[1][i]);
	}
	
	for(int i=0;i<V-1;i++){
		int idx=minValueIndex();
		int node=nodes[idx].first;
		v[node]=1;
		ans+=nodes[idx].second;
		nodes.erase(nodes.begin()+idx);
		
		int tmp=lst[node].size();
		for(int i=0;i<tmp;i++){
			if(v[lst[node][i].first]==0) nodes.push_back(lst[node][i]);	
		}
	}
	
	return ;
}

int main(){
	cin >> V >> E;
	for(int i=0;i<E;i++){
		int p1, p2, value;
		cin >> p1 >> p2 >> value;
		lst[p1].push_back({p2, value});
		lst[p2].push_back({p1, value});
	}
	
	v[1]=1;
	solve();
	cout << ans;
	return 0;
} 
