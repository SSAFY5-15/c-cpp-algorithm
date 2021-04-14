#include <stdio.h>
#include <iostream>
#include <queue> 

using namespace std;

int col, row;
char arr[250][250];
int cnt_v, cnt_k;		// 양, 늑대 누적 개수 
int v, k;		// 구역 당 양, 늑대 개수 

//char arr[10][13]={
//	".###.#####..",
//	"#.kk#...#v#.",
//	"#..k#.#.#.#.",
//	"#..##k#...#.",
//	"#.#v#k###.#.",
//	"#..#v#....#.",
//	"#...v#v####.",
//	".####.#vv.k#",
//	".......####."
//};

//char arr[9][9]={
//	".######.",
//	"#..k...#",
//	"#.####.#",
//	"#.#v.#.#",
//	"#.#.k#k#",
//	"#k.##..#",
//	"#.v..v.#",
//	".######."
//};

// 가장자리면 1, 아니면 0 리턴  
int is_wall(int a, int b){
	if (a==0 || a==row-1 || b==0 || b==col-1) return 1;
	else return 0; 
}

// 동서남북 한칸 위치에서 양, 늑대 체크 후 # 처리
int next(int a, int i){
	int x=a/col;
	int y=a%col;
	int dx[4]={1,0,-1,0};
	int dy[4]={0,1,0,-1};
	
	if((!is_wall(x+dx[i], y+dy[i])) && arr[x+dx[i]][y+dy[i]]!='#'){ 
		if(arr[x+dx[i]][y+dy[i]]=='v') v++;
		else if(arr[x+dx[i]][y+dy[i]]=='k') k++;
		
		arr[x+dx[i]][y+dy[i]]='#';	
		return ((x+dx[i])*col+(y+dy[i]));
	}	
	
	return 0;
}

// 구역당 양, 늑대 수 도출하기
void bfs(){
	queue<int> q;
	
	for(int i=1; i<row-1; i++){			// 가장 자리 제외 for문 
		for(int j=1; j<col-1; j++){
			
			if(arr[i][j]!='#'){
				q.push(i*col+j);		// 1차 배열로 생각했을 떄의 index로 넣기 
				
				while(!q.empty()){
					int t=q.front();
					q.pop();

					if(arr[i][j]=='v') v++; 
					else if(arr[i][j]=='k') k++; 

					arr[i][j]='#';
					for(int L=0; L<4; L++){
						int boool=next(t, L);  
						
						if(boool) q.push(boool);
					}					
				}
				
				if(v<k)	cnt_k+=k;
				else cnt_v+=v;
			
				v=0;
				k=0;
			}
		}
	}
	return ;
}

int main(){
	cin >> row >> col;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin >> arr[i][j];
		}
	}
	
	bfs();
	
	cout << cnt_k << " " << cnt_v;
	
	return 0;
}
