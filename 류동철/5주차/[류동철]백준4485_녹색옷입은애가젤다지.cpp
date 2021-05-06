#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, board[126][126], d[126][126],dd[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
struct pos{int x, y, d;};
bool operator<(pos p, pos q){return p.d > q.d;}

priority_queue<pos> q;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    while(1){
        cin >> n;
        if(n == 0) break;
        memset(d,0x3f,sizeof(d));
        q = priority_queue<pos>();
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> board[i][j];

        int ans = 0; pos c = {0, 0, board[0][0]};
        q.push(c);
        while(!q.empty()){
            if(q.top().x == n-1 && q.top().y == n-1){
                ans = q.top().d;
                break;
            }
            c = q.top(); q.pop();
            d[c.x][c.y] = c.d;
            
            for(int i=0; i<4; i++){
                int nx = c.x+dd[i][0], ny = c.y+dd[i][1];
                if(nx<0 || ny<0 || nx>=n || ny>=n)continue;
                if(d[nx][ny] > c.d+board[nx][ny]){
                    pos new_pos = {nx,ny,c.d+board[nx][ny]};
                    q.push(new_pos);
                }
            }
        }

        cout << "Problem " << tc << ": " << ans << '\n'; tc++;
    }

    return 0;
}