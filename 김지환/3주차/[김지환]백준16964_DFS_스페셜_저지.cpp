#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int N, SEQ[111111] = { 0, };
vector<int> VEC[111111];
int mem[111111] = { 0, };
int main() {
	int st = clock();
	int i, j, tmp1, tmp2;
	cin >> N;
	for (i = 0; i < N-1; i++) {
		cin >> tmp1 >> tmp2;
		VEC[tmp1].push_back(tmp2);
		VEC[tmp2].push_back(tmp1);
	}
	for (i = 0; i < N; i++) cin >> SEQ[i];

	//top = 그래프에서 현재 방문중인 노드 인덱스
	//n = 현재 찾는 순서 인덱스
	//mem[i] = i가 stack상에서 현재 있는 위치
	int n=1, top=SEQ[0], level=1;
	while ( n<N) {
		//cout << top << " ";
		if (mem[SEQ[n]] != 0) {	
			top = SEQ[n];
			level = mem[SEQ[n]];
			mem[SEQ[n++]] = 0;
		}
		else {

			int check = 0;
			for (i = 0; i < VEC[top].size(); i++) {
				if (VEC[top].at(i) == SEQ[n]) check = 1;
				mem[VEC[top].at(i)] = level + 1;
			}

			if (check) {
				mem[SEQ[n]] = 0;
				level++;
				top = SEQ[n++];
			}
			else break;
		}
		
	}
	if (n == N) cout << 1 << endl;
	else cout << 0 << endl;

	//cout << clock() - st << endl;
}