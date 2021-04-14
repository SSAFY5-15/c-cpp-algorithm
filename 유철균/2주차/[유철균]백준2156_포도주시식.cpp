#include <stdio.h>

int g[10001][10001]={0,};
int w_cnt;

// 
void solve(int n){
	if(n==w_cnt+1) return;
	
	if(n==1) g[1][1]=g[0][1];
	if(n==2) {
		g[2][1]=g[0][1];
		g[2][2]=g[0][2];
	}
	
	if(n>=3){
		int ret[3]={0,}; // ���� n-1, n-2. n-3�� �ּ��� ����� ����� ���� �迭 
		
		//solve(n-3)�� �� ���� ���տ��� ����� �ִ밪
		for(int i=1;i<=n-3;i++){
			ret[0]+=g[n-3][i];
		}
		ret[0]=ret[0]+g[0][n-1]+g[0][n];
		
		//solve(n-2)�� �� ���� ���տ��� ����� �ִ밪
		for(int i=1;i<=n-2;i++){
			ret[1]+=g[n-2][i];
		}
		ret[1]+=g[0][n];
		
		//solve(n-1)�� �� ���� ���տ��� ����� �ִ밪
		for(int i=1;i<=n-1;i++){
			ret[2]+=g[n-1][i];
		}
		if(g[n-1][n-1]==0 || g[n-1][n-2]==0 ) ret[2]+=g[0][n];
		
		// �� ���� ��� ������ �ִ밪�� ��쿡 ���� ������ n���� ���� 
		// g[n][1]~g[n][n]�� ���ξ� �ֱ� 
		int ret_max=0;
		for(int i=0;i<3;i++){
			if(ret_max<=ret[i]) ret_max=ret[i];
		}
		
		if(ret[2]==ret_max){
			for(int i=1;i<=n-1;i++){
				g[n][i]=g[n-1][i];
			}
			if(g[n-1][n-1]==0 || g[n-1][n-2]==0) g[n][n]=g[0][n];
			else g[n][n]=0;
		}
		else if(ret[1]==ret_max){
			for(int i=1;i<=n-2;i++){
				g[n][i]=g[n-2][i];
			}
			g[n][n-1]=0;
			g[n][n]=g[0][n];
		}
		else{
			for(int i=1;i<=n-3;i++){
				g[n][i]=g[n-3][i];
			}
			g[n][n-2]=0;
			g[n][n-1]=g[0][n-1];
			g[n][n]=g[0][n];
		}
	}
	
	solve(n+1);
}

int main(){
	scanf("%d", &w_cnt);
	
	for(int i=1;i<=w_cnt;i++){
		int tmp;
		scanf("%d", &tmp);
		g[0][i]=tmp; 
	}
	solve(1);	
	
	int ret=0;
	for(int i=1;i<=w_cnt;i++){
		ret+=g[w_cnt][i];
	}

	printf("%d", ret);
	return 0;
}
