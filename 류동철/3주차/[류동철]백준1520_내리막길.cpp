#include <iostream>
using namespace std;

int n, m;
int board[505][505], d[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
int cnt[505][505];

int solve(int x, int y){
    if(y == n-1 && x == m-1)
        return 1;

    for(int i=0; i<4; i++){
        int nx = x+d[i][0], ny = y+d[i][1];
        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if(cnt[ny][nx] < 0) continue;

        if(board[ny][nx] < board[y][x]){
            if(cnt[ny][nx] > 0) cnt[y][x] += cnt[ny][nx];
            else{
                int t = solve(nx, ny);
                if(t > 0) cnt[y][x] += t;
            }
        }

        if(i == 3 && cnt[y][x] == 0) cnt[y][x] = -1; 
    }

    return cnt[y][x];
}

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << cnt[i][j] << ' ';
        }
        cout << '\n';
    }
    cout <<'\n';
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> board[i][j];

    solve(0, 0);
    cout << cnt[0][0] << '\n';
    // print();
    return 0;
}