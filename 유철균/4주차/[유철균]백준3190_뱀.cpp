#include <iostream>
#include<vector>

using namespace std;

// �ð��� �����鼭 ���� ���� �ֱ�
// �� ��ü, ���� �ε����� �ð� ��ȯ
// ��������� +1, �ƴϸ� �״��
// Ư���ð��� ���� ��ȯ�ϱ�

int N, K, L;
int arr[101][101]={0};
vector<int> moment[10000]; // �� ���� ��ȯ ������ ���� �迭(�ð�, ȸ������)  
int sec; // �ð�(��)

vector<int> head[10000]; // �� �Ӹ� ��ǥ -> index�� �ð�����, ���� ��ǥ�� 
vector<int> tail[10000]; // �� ���� ��ǥ -> ���� ��ǥ�� �ٲ� ������ index�ϳ��� �÷��� ����
int cnt; // �� ���� ��ǥ ��ȯ�� �� ����ϴ� count ����  

int direction; // ��, ��, ��, �� ������ 0, 1, 2, 3���� ������ ���Ⱚ ���� 

int rotation(int s){ // Ư�� �ð� ���� �� �Ӹ� ȸ�� ���� ��ǥ	
	for(int i=0;moment[i].empty()!=true;i++){
		if(moment[i][0]==s){
			if(moment[i][1]==1) return 1; // ������ ȸ���� �� 1���� 
			else return -1; // ���� ȸ���� �� 1����
			break;	
		} 
		if(moment[i+1].empty()==true && moment[i][0]!=s) return 0; // ȸ�� ���� �� 0����
	}
}

int move(int s){ // s�� �� ���� ��Ȳ 
	// s�� �� �� �Ӹ� ��ǥ 
	if(direction==0){
		head[s].push_back(head[s-1][0]);
		head[s].push_back(head[s-1][1]+1);
	} 
	else if(direction==1){
		head[s].push_back(head[s-1][0]+1);
		head[s].push_back(head[s-1][1]);
	} 
	else if(direction==2){
		head[s].push_back(head[s-1][0]);
		head[s].push_back(head[s-1][1]-1);
	} 
	else{
		head[s].push_back(head[s-1][0]-1);
		head[s].push_back(head[s-1][1]);
	}

	int x=head[s][0];
	int y=head[s][1];
	// ���� �� ���� 
	if(x<1 || x>N || y<1 || y>N) return s;
	// ������ ���� �� ���� 
	if(arr[x][y]==-1) return s;
	// �� ���� ��ǥ 
	if(arr[x][y]==0){
		arr[tail[cnt][0]][tail[cnt][1]]=0;
		cnt++;
	
		tail[cnt].push_back(head[cnt][0]);
		tail[cnt].push_back(head[cnt][1]);
	}
	arr[x][y]=-1; // �� ��ü ��ǥ �߰�
	 
	// ���� �� �̵��� ������ �� �Ӹ� ���� ���ϱ� 
	int d=rotation(s);
	if(d==1) direction=(direction+1)%4;
	if(d==-1){
		direction=(direction-1)%4;
		if(direction<0) direction+=4;
	}
	return move(s+1);
}

int main(){
	cin >> N >> K;
	for(int i=0;i<K;i++){
		int x, y;
		cin >> x >> y;

		arr[x][y]=1; // ����� 1�� ǥ�� 
	}
	cin >> L;
	for(int i=0;i<L;i++){
		int x;
		char c;
		
		cin >> x >> c;
		moment[i].push_back(x);
		if(c=='D') moment[i].push_back(1); // ������ ȸ���̸� 1�� ǥ��			
		else moment[i].push_back(-1); // ���� ȸ���̸� -1ǥ��	
	}
	
	arr[1][1]=-1; // ���� -1�� ǥ��
	head[0].push_back(1);
	head[0].push_back(1);
	tail[0].push_back(1);
	tail[0].push_back(1);

	cout << move(1);
	return 0;
}

