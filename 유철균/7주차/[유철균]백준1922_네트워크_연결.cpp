#include <iostream>
#include <vector>

using namespace std;
int N, M; //��� ��, ���� ��

vector<pair<int, int> > nodes; // ���� �����ϴ� ���鿡 ���� (���ο� ������, ���)�� �����ϴ� ���� 
vector<pair<int, int> > p;
vector<vector<pair<int, int> > > neight(1001, p); // index=�ڽų��, pair<�̿����, ���>
int v[10001]={0}; // �湮 
int ans; // �����

int minValueIndex(){ // nodes���� �ּ� ����� ������ �������� index ã�� 
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

void solve(){ // ���� ���� ����� �����带 �߰��ϴ� �� �ݺ��� �ּ� ��� ���
	int tmp=neight[1].size();
	for(int i=0;i<tmp;i++){ // 1�� ��� �̿� �迭 
		nodes.push_back(neight[1][i]);
	}
	
	for(int i=0;i<N-1;i++){
		int idx=minValueIndex();  
		int node=nodes[idx].first; // node�� ���� ������ ��� 
		v[node]=1;
		ans+=nodes[idx].second;
		
		// �߰��� ����� �����带 nodes�� �߰��ϱ�
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
