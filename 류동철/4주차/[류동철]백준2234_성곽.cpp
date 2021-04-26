#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MAX(A, B) ((A)>(B)?(A):(B))

int n, m;
int board[51][51], check[51][51];
int dd[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<int> rooms, res;

int bfs(int x, int y, int cnt){
    queue<pair<int,int> > q;
    q.push(make_pair(x, y));
    int res = 1;
    // cout << "------bfs start-------\n";
    while(!q.empty()){
        x = q.front().first; y = q.front().second;
        q.pop();
        // cout << y << ' ' << x << '\n';
        for(int i=0; i<4; i++){
            // 벽인 경우
            if(board[y][x] & (1<<i)) continue;
            int nx = x+dd[i][0], ny = y+dd[i][1];
            if(nx <0 || ny<0 || nx>=n || ny>=m || check[ny][nx]) continue;
            check[ny][nx] = cnt;
            q.push(make_pair(nx, ny));
            res++;
        }
    }
    // cout <<res << '\n';
    return res;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    int cnt = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j]){
                check[i][j] = cnt;
                int t = bfs(j,i,cnt++);
                rooms.push_back(t);
            }
        }
    }
    cout << cnt-1 << '\n' << *max_element(rooms.begin(),rooms.end()) << '\n';
    
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] != check[i-1][j]){
                res.push_back(rooms[check[i][j]-1]+rooms[check[i-1][j]-1]); 
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=1; j<n; j++){
            if(check[i][j] != check[i][j-1]){
                res.push_back(rooms[check[i][j]-1]+rooms[check[i][j-1]-1]);
            }
        }
    }

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         for(int k=0; k<4; k++){
    //             if(board[i][j] & (1<<k)){
    //                 memset(check,0,sizeof(check));
    //                 board[i][j] -= (1<<k);
    //                 check[i][j] = 1;
    //                 res = max(res, bfs(j,i));
    //                 board[i][j] += (1<<k);
    //             }
    //         }
    //     }
    // }
    
    cout << *max_element(res.begin(), res.end()) << '\n';
    return 0;
}