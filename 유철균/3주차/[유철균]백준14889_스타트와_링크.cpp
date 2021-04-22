#include <iostream>
using namespace std;

int N; 	// �� �ο� 
int sum_total;  
int dif=100*10; // �� �ɷ�ġ ���� 

int arr[20][20]; // �Է� �迭 

// ������ ���տ��� dif ���ϴ� �Լ� 
void perm(int *t){
	int sum1=0; // ��1 �ɷ�ġ �� 
	int sum2=0; // ��2 �ɷ�ġ ��
		
	for(int i=0;i<N/2;i++){
		for(int j=0;j<N/2;j++){
			sum1+=arr[t[i]][t[j]];	
		}
	}
	
	int sum2_arr[N]={0}; // ��ü �ѹ� �迭 
	for(int i=0;i<N;i++){
		for(int j=0;j<N/2;j++){
			if(i==t[j]) {
				sum2_arr[i]=-1; // ��1�� ���� �ѹ��� ��� -1 ó�� 
				break;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		if(sum2_arr[i]==0) sum2_arr[i]=i; 
	}
	int t2[N/2]; // ��2�� ���� �ѹ����� ������ �迭
	
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
	
	if(tmp<0) tmp=-tmp; // ���밪 ó�� 
	if(dif>tmp) dif=tmp;
	
	return ;
}

// �� ������ �����ϴ� ���� �Լ�
void comb(int s, int *t, int cnt){ // s: ���տ��� start ����, t: �Ѱܹ޾� ������ �ӽ� �迭, cnt: ��� ȣ�� ����  
	if(cnt==N/2){ // ������ ������ŭ t�迭�� á���� perm�Լ� ���� 
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

	int t[N/2]; // �� ������ ������ �ӽ� �迭 
	comb(0, t, 0);
	
	cout << dif;
	return 0;
}
