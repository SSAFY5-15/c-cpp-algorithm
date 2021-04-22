#include <iostream>
#include <vector>
#include <string.h>
#include <memory.h>
#define MAX 100002
// 왜 100000으로 하면 안되는지 모르겠음...

using namespace std;

int N; // 노드 개수 
vector<int> vec[MAX]; // 노드 입력 배열 
int ans=1; // 출력값 
int visit[MAX]; // 방문처리 
int order[MAX]; // 마지막 입력값 배열 
int next; // 검증할 다음 노드 

void solve(int x){ // x는 order의 번째를 말함 ex) 0번 index는 1번째로 생각 
	int t=order[x];
	visit[t]=1;
	
	int len=vec[t].size();
	int next=order[x+1];
	int flag=0; // dfs 방식으로 연결된 노드를 쭉 따라가는지 여부 저장 변수 
	for(int i=0;i<len;i++){
		if(visit[next]==0){ // 다음 노드를 방문하지 않았다면 -> 없어도 될 듯? 
			if (vec[t][i]==next && x!=N){ // 검증할 다음 노드가 현재 노드와 연결되있고, 현재노드가 마지막 노드가 아니라면 진행 
				solve(x+1);
				flag=1; 
			}
		}
		
		if(i==len-1 && flag==0){ // 현재 노드에서 dfs가 돌아가지 않았을 때 
			for(int j=0;j<len;j++){ 
				if(visit[vec[t][j]]==0){  // 연결된 노드 중 방문하지 않은 곳이 있다면 유저의 정답이 잘못됨
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
		vec[a].push_back(b); // 연결된 노드 추가 
		vec[b].push_back(a);		
	}
	for(int i=1; i<=N; i++){
		cin >> order[i];
	}
	order[0]=0; // index와 노드 번호 일치화
	
	solve(1);
	if(order[1]!=1) cout << "0"; // 시작 노드가 1이 아닌 경우 유저의 정답이 잘못됨 
	else cout << ans; 
	
	return 0;
}
