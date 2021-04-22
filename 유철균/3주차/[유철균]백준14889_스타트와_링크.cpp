#include <iostream>
using namespace std;

int N; 	// 총 인원 
int sum_total;  
int dif=100*10; // 팀 능력치 차이 

int arr[20][20]; // 입력 배열 

// 결정된 조합에서 dif 구하는 함수 
void perm(int *t){
	int sum1=0; // 팀1 능력치 합 
	int sum2=0; // 팀2 능력치 합
		
	for(int i=0;i<N/2;i++){
		for(int j=0;j<N/2;j++){
			sum1+=arr[t[i]][t[j]];	
		}
	}
	
	int sum2_arr[N]={0}; // 전체 넘버 배열 
	for(int i=0;i<N;i++){
		for(int j=0;j<N/2;j++){
			if(i==t[j]) {
				sum2_arr[i]=-1; // 팀1에 속한 넘버일 경우 -1 처리 
				break;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		if(sum2_arr[i]==0) sum2_arr[i]=i; 
	}
	int t2[N/2]; // 팀2에 속한 넘버들을 저장할 배열
	
	int x=0;
	for(int i=0;i<N;i++){
		if(sum2_arr[i]!=-1) t2[x++]=sum2_arr[i];
	}
	
	for(int i=0;i<N/2;i++){
		for(int j=0;j<N/2;j++){
			sum2+=arr[t2[i]][t2[j]];	
		}
	}
	
	int tmp=sum2-sum1;
	
	if(tmp<0) tmp=-tmp; // 절대값 처리 
	if(dif>tmp) dif=tmp;
	
	return ;
}

// 팀 조합을 결정하는 조합 함수
void comb(int s, int *t, int cnt){ // s: 조합에서 start 지점, t: 넘겨받아 저장할 임시 배열, cnt: 재귀 호출 개수  
	if(cnt==N/2){ // 조합할 개수만큼 t배열이 찼으면 perm함수 실행 
		perm(t);
		return ;
	}
	for(int i=s;i<N/2+cnt+1;i++){
		t[cnt]=i;
		comb(i+1, t, cnt+1);
	}
	
	return ;
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
			sum_total+=	arr[i][j];
		}
	}

	int t[N/2]; // 팀 조합을 저장할 임시 배열 
	comb(0, t, 0);
	
	cout << dif;
	return 0;
}
