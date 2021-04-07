#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
char bud[9];
int visited[10];
int arr[10];

string ans;
vector<string> result;

void find(string ans, int cnt) {
	if (cnt == k) {
		result.push_back(ans);
		return;
	}
	if (bud[cnt] == '<') {
		int temp = ans[cnt] - '0';
		for (int i = 0; i < 10; ++i) {
			if (temp >= i) continue;
			if (!visited[i]) {
				visited[i] = 1;
				ans += (i + '0');
				find(ans, cnt + 1);
				visited[i] = 0;
				ans.pop_back();
			}
		}
	}
	else {
		int temp = ans[cnt] - '0';
		for (int i = 0; i < 10; ++i) {
			if (temp <= i) continue;
			if (!visited[i]) {
				visited[i] = 1;
				ans += (i + '0');
				find(ans, cnt + 1);
				visited[i] = 0;
				ans.pop_back();
			}
		}
	}
}

int main(){
	cin >> k;
	for (int i = 0; i < k; ++i) cin >> bud[i];
	for (int i = 0; i < 10; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			ans += (i + '0');
			find(ans, 0);
			visited[i] = 0;
			ans.pop_back();
		}
	}
	cout << result[result.size() - 1] << endl;
	cout << result[0] << endl;
	return 0;
}