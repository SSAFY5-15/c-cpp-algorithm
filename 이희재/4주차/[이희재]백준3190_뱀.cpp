#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
queue<pair<int, int>> snake;
pair<int, int> snake_head;
char snake_move[10001];
int N, K, L, direction, s;
// 방향++는 오른쪽 방향으로 회전
// 방향--는 왼쪽 방향으로 회전
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


void init() {
	for (int i = 0; i < 101; i++)    memset(map[i], 0, sizeof(int) * 101);
	memset(snake_move, 0, sizeof(char) * 10001);
	
	snake_head = { 1, 1 };
	snake.push({ 1, 1 });
	map[1][1] = 1;

	direction = 0;
	s = 0;
}

bool is_valid(int y, int x) {
	if (y < 1 || y > N)    return false;
	if (x < 1 || x > N)    return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	init();

	cin >> N;

	// 맵에 사과를 세팅
	cin >> K;
	for (int apple = 0; apple < K; apple++) {
		int y, x; 
		cin >> y >> x;
		map[y][x] = 2;
	}

	// 뱀의 이동정보를 배열 snake_move에 세팅
	cin >> L;
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		snake_move[X] = C;
	}

	while (1) {
		s++;
		int new_y = snake_head.first + dy[direction];
		int new_x = snake_head.second + dx[direction];
		
		if (is_valid(new_y, new_x)) {
			if (map[new_y][new_x] == 1)    break;

			if (map[new_y][new_x] == 0) {
				pair<int, int> tail = snake.front();
				map[tail.first][tail.second] = 0;
				snake.pop();
			}
			snake_head = { new_y, new_x };
			snake.push({ new_y, new_x });
			map[new_y][new_x] = 1;
		}
		else    break;

		if (snake_move[s] == 'D')
			direction = (direction + 1) % 4;
		else if (snake_move[s] == 'L') {
			if (direction == 0)    direction = 3;
			else    direction = direction - 1;
		}
	}

	cout << s << '\n';

	return 0;
}