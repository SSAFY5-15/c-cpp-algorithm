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
	
	if(dp[n-1]==dp[n-2]){ // ���� �̹� ���� ����������, N-1���� ���۵Ǵ� ���������� �����ؾ� ��
		if(lst[n-1]<0){ // �̹� ���� �������̶��
			if(lst[n]>=0) dp[n]=lst[n]; // ���� ���۵Ǵ� ������
			else dp[n]=dp[n-1];	// ���� �������� �״�� �̾��� 
			return solve(n+1);
		}	
	}
	// N-1���� ���۵Ǵ� �������̶�� ó���� d[1] �������� ��ó�� ������ ���� 3���� ��찡 ������ 
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
	// �� 3���� ���� ���� �� ���� 
	if(dp[0]+lst[1]>0) dp[1]=dp[0]+lst[1]; // ���� 0���� Ŭ�� 
	else if(lst[1]<dp[0]) dp[1]=dp[0]; // ���� ������ ���� �������� Ŭ��  
	else dp[1]=lst[1]; // ���簪�� ���� ���������� Ŭ�� 
	
	cout << solve(2);
//	for(int i=0;dp[i]!=0;i++){
//		cout << dp[i] << "  ";
//	}
	
	return 0;
} 
