#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
int n, m, board[1001][1001], dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, ret = 0;
queue<pair<pii,int > > q;

void bfs(){
    while(!q.empty()){
        int y = q.front().first.first, x = q.front().first.second, cnt = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dir[i][0], ny = y+dir[i][1];
            if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
            if(board[ny][nx] == 0){
                q.push(make_pair(make_pair(ny,nx),cnt+1));
                board[ny][nx] = 1;
            }
        }
        ret = max(ret, cnt);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) q.push(make_pair(make_pair(i,j),0));
        }
    }
    
    bfs();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 0){
                ret = -1;
                i = n;
                break;
            }
        }
    }

    cout << ret << '\n';
    return 0;
}