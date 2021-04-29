#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, K, S, X, Y;
int board[201][201];
int dd[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<vector<pair<int,int> > > v, v2;

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x+dd[i][0], ny = y+dd[i][1];
        if(nx<=0 || ny<=0 || nx>n || ny>n) continue;
        if(board[nx][ny] == 0){
            board[nx][ny] = board[x][y];
            v2[board[x][y]].push_back(make_pair(nx,ny));
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> K;
    v.resize(K+1);
    v2.resize(K+1);
    for(int i=1; i<=n; i++)for(int j=1; j<=n; j++){
        cin >> board[i][j];
        if(board[i][j]) v[board[i][j]].push_back(make_pair(i, j));
    }
    cin >> S >> X >> Y;

    for(int s=1; s<=S; s++){
        for(int i=1; i<=K; i++){
            for(int j=0; j<v[i].size(); j++){
                dfs(v[i][j].first, v[i][j].second);
            }
        }
        v.clear();v.resize(K+1);
        for(int i=1; i<=K; i++){
            for(int j=0; j<v2[i].size(); j++){
                v[i].push_back(make_pair(v2[i][j].first,v2[i][j].second));
            }
        }
        v2.clear();v2.resize(K+1);
    }

    cout<<board[X][Y]<<'\n';
    return 0;
}