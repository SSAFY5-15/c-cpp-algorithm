#include <iostream>
#include <cstring>
using namespace std;

int map[500][500], table[500][500];
int N, M;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };


void init() {
    for (int i = 0; i < 500; i++) {
        memset(map[i], 0, sizeof(int) * 500);
        memset(table[i], -1, sizeof(int) * 500);
    }
    table[0][0] = 1;
}

bool is_valid(int y, int x) {
    if (y < 0 || y >= N)    return false;
    if (x < 0 || x >= M)    return false;
    return true;
}

int dfs(int y, int x) {
    int tmp = 0;
    if (y == N - 1 && x == M - 1)    return 1;
    else {
        for (int i = 0; i < 4; i++)
            if (is_valid(y + dy[i], x + dx[i])) {
                int new_y = y + dy[i];
                int new_x = x + dx[i];
                if (map[new_y][new_x] < map[y][x]) {
                    if (table[new_y][new_x] != -1)    tmp += table[new_y][new_x];
                    else    tmp += dfs(new_y, new_x);
                }
            }
        table[y][x] = tmp;
        return tmp;
    }
}

int main() {
    // 초기화
    ios_base::sync_with_stdio(false);
    init();

    // map 정보 입력
    cin >> N >> M;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> map[y][x];

    dfs(0, 0);

    cout << table[0][0] << '\n';
    return 0;
}