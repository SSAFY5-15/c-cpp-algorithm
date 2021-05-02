#include <iostream>

using namespace std;

int N;
int dp[1000][3];
int arr[1000][3];

void solve(int cnt){ 
	if(cnt==N) return ;
		 
	for(int i=0; i<3; i++){
		int t=1000*1000+1; // 1001ÀÌ ¾Æ´Ô!! 
		for(int j=0; j<3; j++){
			if(i!=j && t>dp[cnt-1][j]) t=dp[cnt-1][j];
		}
		dp[cnt][i]=arr[cnt][i]+t;
	}
	
	solve(cnt+1);
	return ;
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cin >> arr[i][j];   
		}
	}

	for(int i=0; i<3; i++){
		dp[0][i]=arr[0][i];
	}
	
	solve(1);
	
	int ret=1000*1000+1;
	for(int i=0; i<3; i++){
		if(ret>dp[N-1][i]) ret=dp[N-1][i];
	}		

	cout << ret << endl;
	return 0;
}
