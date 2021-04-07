#include <iosteam>
using namespace std;
int N, arr[10] = { 0, };
int swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void p(int n) {
	int i, j;
	if (n == N) {
		for (i = 0; i < n; i++) cout << arr[n] << " ";
		cout << "\n";
		return;
	}
	for (i = n + 1; i <= N; i++) {
		swap(arr[n], arr[i]);
		p(n + 1);
		swap(arr[i], arr[n]);

	}

}
int main() {
	int n;

	cin >> N;
	for (i = 0; i <= N; i++) arr[i] = i;
	p(0);

}