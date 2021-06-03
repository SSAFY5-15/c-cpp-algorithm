#include <iostream>

using namespace std;

int arr[6][3];
int ans;

void perm(int t[][6],int cnt){ // ������ ���� ����Ž���ϱ�, cnt�� ��� ȸ�� 
	int row=cnt/6;
	int col=cnt%6;
	
	if(col==0 && cnt>0){ // ���� ���� ��� ä������ �� �������� �־��� ������� ���� ans �Ǻ��ϱ� 
		int winSum=0;
		int tieSum=0;
		int loseSum=0;
		
		for(int i=0;i<6;i++){
			if(t[row-1][i]==1) winSum+=1;	
			else if(t[row-1][i]==2) tieSum+=1;	
			else if(t[row-1][i]==3) loseSum+=1;
		}
		if(arr[row-1][0]!=winSum || arr[row-1][1]!=tieSum || arr[row-1][2]!=loseSum){ // �־��� ���� �ٸ��� ���� 
			return ;
		}
	}
	if(cnt==36){ // ��� �࿡�� �־��� ���� ������ �� �� ���Ҵٸ� ans�� ���� 1�� �� 
		ans=1;
		return ;
	}
	
	if(col>row){ // �� ���ǰ� �ݴ�Ǵ� ��Ȳ�� ���� �ڵ忡 ���� �������� ex) a�� b�� ���ϸ�, b�� a�� ���ϰ� �� 
		for(int i=1;i<=3;i++){ // �̱�� 1, ����2, ���� �� 3 �� ����
			t[row][col]=i;  
			if(i==1) t[col][row]=3;
			else if(i==2) t[col][row]=2;
			else t[col][row]=1;
			perm(t, cnt+1); // �̷��� 15�� �ݺ��ϰ� �� -> �ð� ���⵵ 10�� �ȵǼ� �ð� ������
							// cnt�� �����ؼ� �� ���� ä������ �� ans�� �����ϱ� ����,cnt�� 15�� �ƴ� 36���� ������				
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
	int anss[4]; // �� �� ans�� �����ϴ� �迭 
	for(int tc=0;tc<4;tc++){
		ans=0;
		for(int i=0;i<6;i++){
			for(int j=0;j<3;j++){
				cin >> arr[i][j];
			}
		}
		
		int p[6][6]={0}; // �� ���� ����� �����ϴ� �迭 
		perm(p, 0);
		anss[tc]=ans;
	}
	
	for(int i=0;i<4;i++){
		cout << anss[i] << " ";	
	}
	
	return 0;
} 
