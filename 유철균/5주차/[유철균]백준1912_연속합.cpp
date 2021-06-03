#include <iostream>

using namespace std;

int N;
int lst[100000];
int dp[100000]; 

int solve(int n){
	if(n==N){		
		int ret=-1000;
		for(int i=0;i<N;i++){
			if(ret<dp[i]) ret=dp[i];
		}

		return ret;
	}
	
	if(dp[n-1]==dp[n-2]){ // 먼저 이미 끊긴 연속합인지, N-1에서 시작되는 연속합인지 구분해야 함
		if(lst[n-1]<0){ // 이미 끊긴 연솝합이라면
			if(lst[n]>=0) dp[n]=lst[n]; // 새로 시작되는 연속합
			else dp[n]=dp[n-1];	// 이전 누적값이 그대로 이어짐 
			return solve(n+1);
		}	
	}
	// N-1에서 시작되는 연속합이라면 처음에 d[1] 도출했을 때처럼 다음과 같이 3가지 경우가 존재함 
	if(dp[n-1]+lst[n]>0) dp[n]=dp[n-1]+lst[n];
	else{
		if(dp[n-1]<lst[n]) dp[n]=lst[n];
		else dp[n]=dp[n-1];
	}
		
	return solve(n+1);	
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> lst[i];
	}
	if(N==1) {
		cout << lst[0];
		return 0;	
	}

	dp[0]=lst[0];
	// 총 3개의 경우로 나뉠 수 있음 
	if(dp[0]+lst[1]>0) dp[1]=dp[0]+lst[1]; // 합이 0보다 클때 
	else if(lst[1]<dp[0]) dp[1]=dp[0]; // 현재 값보다 이전 누적값이 클때  
	else dp[1]=lst[1]; // 현재값이 이전 누적값보다 클때 
	
	cout << solve(2);
//	for(int i=0;dp[i]!=0;i++){
//		cout << dp[i] << "  ";
//	}
	
	return 0;
} 
