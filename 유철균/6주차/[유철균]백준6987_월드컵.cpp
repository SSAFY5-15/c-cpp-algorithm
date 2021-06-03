#include <iostream>

using namespace std;

int arr[6][3];
int ans;

void perm(int t[][6],int cnt){ // 순열에 대해 완전탐색하기, cnt는 재귀 회수 
	int row=cnt/6;
	int col=cnt%6;
	
	if(col==0 && cnt>0){ // 행의 수가 모두 채워졌을 때 문제에서 주어진 결과값과 비교해 ans 판별하기 
		int winSum=0;
		int tieSum=0;
		int loseSum=0;
		
		for(int i=0;i<6;i++){
			if(t[row-1][i]==1) winSum+=1;	
			else if(t[row-1][i]==2) tieSum+=1;	
			else if(t[row-1][i]==3) loseSum+=1;
		}
		if(arr[row-1][0]!=winSum || arr[row-1][1]!=tieSum || arr[row-1][2]!=loseSum){ // 주어진 값과 다르면 실행 
			return ;
		}
	}
	if(cnt==36){ // 모든 행에서 주어진 값과 비교했을 때 다 같았다면 ans는 드디어 1이 됨 
		ans=1;
		return ;
	}
	
	if(col>row){ // 이 조건과 반대되는 상황은 밑의 코드에 따라 저장해줌 ex) a가 b에 승하면, b는 a에 패하게 됨 
		for(int i=1;i<=3;i++){ // 이기면 1, 비기면2, 지는 건 3 을 저장
			t[row][col]=i;  
			if(i==1) t[col][row]=3;
			else if(i==2) t[col][row]=2;
			else t[col][row]=1;
			perm(t, cnt+1); // 이렇게 15반 반복하게 됨 -> 시간 복잡도 10억 안되서 시간 괜찮음
							// cnt에 의존해서 한 행이 채워졌을 때 ans를 도출하기 위해,cnt를 15가 아닌 36까지 돌려줌				
			if(ans==1) return ;		
		}	
	}
	else {
		perm(t, cnt+1);
		if(ans==1) return ;
	}
	
	return ;	 
}

int main(){
	int anss[4]; // 각 조 ans를 저장하는 배열 
	for(int tc=0;tc<4;tc++){
		ans=0;
		for(int i=0;i<6;i++){
			for(int j=0;j<3;j++){
				cin >> arr[i][j];
			}
		}
		
		int p[6][6]={0}; // 각 팀의 결과를 저장하는 배열 
		perm(p, 0);
		anss[tc]=ans;
	}
	
	for(int i=0;i<4;i++){
		cout << anss[i] << " ";	
	}
	
	return 0;
} 
