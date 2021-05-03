#include <iostream>
#include<vector>

using namespace std;

// 시간이 지나면서 뱀의 행적 넣기
// 뱀 자체, 벽에 부딪히면 시간 반환
// 사과먹으면 +1, 아니면 그대로
// 특정시간에 방향 전환하기

int N, K, L;
int arr[101][101]={0};
vector<int> moment[10000]; // 뱀 방향 전환 순서쌍 넣을 배열(시간, 회전방향)  
int sec; // 시간(초)

vector<int> head[10000]; // 뱀 머리 좌표 -> index를 시간으로, 값을 좌표로 
vector<int> tail[10000]; // 뱀 꼬리 좌표 -> 꼬리 좌표가 바뀔 떄마다 index하나씩 늘려서 저장
int cnt; // 뱀 꼬리 좌표 변환할 때 사용하는 count 변수  

int direction; // 동, 남, 서, 북 순으로 0, 1, 2, 3값을 가지게 방향값 설정 

int rotation(int s){ // 특정 시간 직후 뱀 머리 회전 방향 좌표	
	for(int i=0;moment[i].empty()!=true;i++){
		if(moment[i][0]==s){
			if(moment[i][1]==1) return 1; // 오른쪽 회전일 때 1리턴 
			else return -1; // 왼쪽 회전일 때 1리턴
			break;	
		} 
		if(moment[i+1].empty()==true && moment[i][0]!=s) return 0; // 회전 안할 때 0리턴
	}
}

int move(int s){ // s초 후 진행 상황 
	// s초 후 뱀 머리 좌표 
	if(direction==0){
		head[s].push_back(head[s-1][0]);
		head[s].push_back(head[s-1][1]+1);
	} 
	else if(direction==1){
		head[s].push_back(head[s-1][0]+1);
		head[s].push_back(head[s-1][1]);
	} 
	else if(direction==2){
		head[s].push_back(head[s-1][0]);
		head[s].push_back(head[s-1][1]-1);
	} 
	else{
		head[s].push_back(head[s-1][0]-1);
		head[s].push_back(head[s-1][1]);
	}

	int x=head[s][0];
	int y=head[s][1];
	// 벽일 때 종료 
	if(x<1 || x>N || y<1 || y>N) return s;
	// 지한테 갔을 때 종료 
	if(arr[x][y]==-1) return s;
	// 뱀 꼬리 좌표 
	if(arr[x][y]==0){
		arr[tail[cnt][0]][tail[cnt][1]]=0;
		cnt++;
	
		tail[cnt].push_back(head[cnt][0]);
		tail[cnt].push_back(head[cnt][1]);
	}
	arr[x][y]=-1; // 뱀 전체 좌표 추가
	 
	// 뱀의 몸 이동이 끝나고 뱀 머리 방향 정하기 
	int d=rotation(s);
	if(d==1) direction=(direction+1)%4;
	if(d==-1){
		direction=(direction-1)%4;
		if(direction<0) direction+=4;
	}
	return move(s+1);
}

int main(){
	cin >> N >> K;
	for(int i=0;i<K;i++){
		int x, y;
		cin >> x >> y;

		arr[x][y]=1; // 사과는 1로 표시 
	}
	cin >> L;
	for(int i=0;i<L;i++){
		int x;
		char c;
		
		cin >> x >> c;
		moment[i].push_back(x);
		if(c=='D') moment[i].push_back(1); // 오른쪽 회전이면 1로 표시			
		else moment[i].push_back(-1); // 왼쪽 회전이면 -1표시	
	}
	
	arr[1][1]=-1; // 뱀은 -1로 표시
	head[0].push_back(1);
	head[0].push_back(1);
	tail[0].push_back(1);
	tail[0].push_back(1);

	cout << move(1);
	return 0;
}

