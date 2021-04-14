#include <stdio.h>
#include <iostream>
#include <queue> 

using namespace std;

int col, row;
char arr[250][250];
int cnt_v, cnt_k;		// ��, ���� ���� ���� 
int v, k;		// ���� �� ��, ���� ���� 

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

// �����ڸ��� 1, �ƴϸ� 0 ����  
int is_wall(int a, int b){
	if (a==0 || a==row-1 || b==0 || b==col-1) return 1;
	else return 0; 
}

// �������� ��ĭ ��ġ���� ��, ���� üũ �� # ó��
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

// ������ ��, ���� �� �����ϱ�
void bfs(){
	queue<int> q;
	
	for(int i=1; i<row-1; i++){			// ���� �ڸ� ���� for�� 
		for(int j=1; j<col-1; j++){
			
			if(arr[i][j]!='#'){
				q.push(i*col+j);		// 1�� �迭�� �������� ���� index�� �ֱ� 
				
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
