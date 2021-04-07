#include<iostream>

using namespace std;

int B[101][101];
int Q[101];
int front = 0;
int tail = 0;
int check[101];
int ans = 0;
int ureka = 0;

void enque(int n) {
	if (Q[tail + 1] != '\0') {
		//printf("Q is full");
		return;
	}
	Q[tail++] = n;
	if (tail == 100) tail = 0;
}

int deque() {
	int n = Q[front];
	Q[front++] = '\0';
	if (front == 100) front = 0;
	return n;
}

void bfs(int T1, int T2) {
	int line = Q[tail-1];
	ans = 1;
	while (front!=tail) {		
		int n = deque();
		int cnt = 0;
		while (B[n][cnt]) {
			if (check[B[n][cnt]] == 0) {
				enque(B[n][cnt]);				
				check[B[n][cnt]] = 1;
				if (B[n][cnt] == T2) {
					ureka = 1;
					break;
				}
			}
			cnt++;
		}
		if (ureka == 1) break;
		if (n == line) {
			line = Q[tail - 1];
			ans++;
		}		
	}
}

int main() {
	int N; int T1; int T2; int M;
	cin >> N >> T1 >> T2 >> M;
	int a; int b; int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cnt = 0;
		while (B[a][cnt] != 0) {
			cnt++;
		}
		B[a][cnt] = b;

		cnt = 0;
		while (B[b][cnt] != 0) {
			cnt++;
		}
		B[b][cnt] = a;
	}
	enque(T1);
	check[T1] = 2;
	bfs(T1,T2);

	if (ureka == 1) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}