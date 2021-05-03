#include<iostream>
#include<deque>
using namespace std;

int n, k, l;
int board[102][102], dir[101], t[101], dd[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
deque<pair<int, int> > dq;

void print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<k; i++){
        int a, b; cin >> a >> b;
        board[a][b] = 1;
    }
    board[1][1] = 2;
    dq.push_back({1,1});

    cin >> l;
    for(int i=0; i<l; i++){
        int a; char b; cin >> a >> b;
        t[i] = a, dir[i] = (b=='D')?1:-1;
    }

    int curTime=0, curDir=0, idx=0;
    bool fin = false;
    while(1){
        int changeTime = -1, changeDir = 0;
        if(idx < l){
            changeTime = t[idx], changeDir = dir[idx];
            idx++;
        }
        // 머리 움직이기
        while(changeTime<0 || curTime < changeTime){
            // cout << curTime << '\n';
            curTime++;
            // print();
            int nx = dq.back().second+dd[curDir][0], ny = dq.back().first+dd[curDir][1];
            if(ny <= 0 || nx <= 0 || ny > n || nx > n){
                fin = true;
                break;
            }
            // 뱀인 경우 끝내기
            if (board[ny][nx] == 2){
                fin = true;
                break;
            }

            // 사과가 아닌 경우 길이 줄여주기
            if(board[ny][nx] == 0){
                board[dq.front().first][dq.front().second] = 0;
                dq.pop_front();
            }
            board[ny][nx] = 2;
            dq.push_back({ny,nx});
        }
        if(fin) break;

        if(changeTime > 0){
            curDir += changeDir;
            if(curDir < 0) curDir = 3;
            if(curDir >= 4) curDir = 0;
        }
    }
    
    cout << curTime << '\n';

    return 0;
}