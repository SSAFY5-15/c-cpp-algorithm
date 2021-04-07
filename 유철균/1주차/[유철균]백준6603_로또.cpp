#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int k;

void comb(int s, int e,vector<int> &vec, int cnt,vector<int> &t){
	if(cnt==6){
		for(int i=0;i<6;i++){
			cout << t[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i=s;i<=e;i++){
		t[cnt]=vec[i];
		comb(i+1, k+cnt-5, vec, cnt+1, t);
	}
	return ;
}

int main(){
	while(1){
		vector<int> vec(13,0);
		vector<int> t(6,0);

		cin >> k;
		if(k==0) break;
		for(int i=0;i<k;i++){
			int x;
			cin >> x;
			vec[i]=x;
		}
		
		comb(0, k-5, vec, 0, t);
		cout << "\n";
	}
	return 0;
}
