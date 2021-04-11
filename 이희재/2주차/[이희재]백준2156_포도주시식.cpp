#include <iostream>
#include <cstring>
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;
int wine[10000], table[10000];
int n, maximum;

void init() {
	memset(table, 0, sizeof(int));
	maximum = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	init();
	cin >> n;

	for (int i = 0; i < n; i++)    cin >> wine[i];

	table[0] = wine[0];
	if (n > 1)    table[1] = wine[0] + wine[1];
	if (n > 2) {
		table[2] = MAX(table[0] + wine[2], table[1]);
		table[2] = MAX(table[2], wine[1] + wine[2]);
	}
	for (int i = 3; i < n; i++) {
		table[i] = MAX(table[i - 2] + wine[i], table[i - 3] + wine[i - 1] + wine[i]);
		table[i] = MAX(table[i], table[i - 3] + wine[i]);
		if (i > 4)
			table[i] = MAX(table[i], table[i - 4] + wine[i - 1] + wine[i]);
	}
	
	maximum = table[n - 1];
	if (n > 1)    maximum = MAX(maximum, table[n - 2]);
	cout << maximum << '\n';
	return 0;
}