#include <iostream>
#include <vector>
#include <string.h>
#include <memory.h>
#define MAX 100002
// �� 100000���� �ϸ� �ȵǴ��� �𸣰���...

using namespace std;

int N; // ��� ���� 
vector<int> vec[MAX]; // ��� �Է� �迭 
int ans=1; // ��°� 
int visit[MAX]; // �湮ó�� 
int order[MAX]; // ������ �Է°� �迭 
int next; // ������ ���� ��� 

void solve(int x){ // x�� order�� ��°�� ���� ex) 0�� index�� 1��°�� ���� 
	int t=order[x];
	visit[t]=1;
	
	int len=vec[t].size();
	int next=order[x+1];
	int flag=0; // dfs ������� ����� ��带 �� ���󰡴��� ���� ���� ���� 
	for(int i=0;i<len;i++){
		if(visit[next]==0){ // ���� ��带 �湮���� �ʾҴٸ� -> ��� �� ��? 
			if (vec[t][i]==next && x!=N){ // ������ ���� ��尡 ���� ���� ������ְ�, �����尡 ������ ��尡 �ƴ϶�� ���� 
				solve(x+1);
				flag=1; 
			}
		}
		
		if(i==len-1 && flag==0){ // ���� ��忡�� dfs�� ���ư��� �ʾ��� �� 
			for(int j=0;j<len;j++){ 
				if(visit[vec[t][j]]==0){  // ����� ��� �� �湮���� ���� ���� �ִٸ� ������ ������ �߸���
					ans=0;
					return;
				}
			}
		}
	}

	return ;
}


int main(){
	cin >> N;
	
	memset(visit, 0, sizeof(int)*N); 

	for(int i=0; i<N-1; i++){
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b); // ����� ��� �߰� 
		vec[b].push_back(a);		
	}
	for(int i=1; i<=N; i++){
		cin >> order[i];
	}
	order[0]=0; // index�� ��� ��ȣ ��ġȭ
	
	solve(1);
	if(order[1]!=1) cout << "0"; // ���� ��尡 1�� �ƴ� ��� ������ ������ �߸��� 
	else cout << ans; 
	
	return 0;
}
