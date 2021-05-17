#include <iostream>
#include <vector>
#include <string.h>
#define INF 100000000

using namespace std;

int tc;
int n, d, c; // �İ���, ����������, ��ŷ�� ���� ��ȣ 

vector<pair<int, int> > vec;
vector<vector<pair<int, int> > > lst(10001,vec);
int v[10001]; // �湮����
int acc[10001]; // ������ �����ϴ� �迭 
int cnt; // �����Ǵ� com ����

int getSmallNode(){ // ���� ���� ���� �ð��� ������ com ��ȣ ���ϱ� 
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
		int node=getSmallNode(); // ��� ��� �� ������ �ּ��� node�� �湮 ǥ�� 
		if(node==-1) { // �� �̻� �湮�� com�� ���ٸ� 
			for(int i=1;i<=n;i++){
				if(acc[i]!=INF && ans<acc[i]){
					ans=acc[i];
				}
			}
			break;
		}
		
		v[node]=++cnt;
		int size=lst[node].size();
		for(int j=0;j<size;j++){ // node�� ����� ���� nnode�� ���� ������ �ֽ�ȭ
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
			acc[lst[c][i].first]=lst[c][i].second; // ������ �迭�� �ֱ�
		}
		v[c]=++cnt;
		int ans=dijkstra();
		
		cout << cnt << " " << ans << "\n";
	}
	
	return 0;
}
