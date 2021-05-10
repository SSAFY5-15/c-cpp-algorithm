#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 크기, 무지개블록 제일 많은 것, 행, 열
struct blockGroup{
    // 기준 블록의 행, 열
    int x, y, val;
    // 배열 저장
    bool tempcheck[21][21];
    // 크기, 무지개 개수
    int size, num;
};

int n, m, dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}}, res, rot;
int blocks[21][21];
bool check[21][21];
blockGroup b, b1;

bool compare(blockGroup bg1, blockGroup bg2){
    if(bg1.size != bg2.size) return bg1.size > bg2.size;
    if(bg1.num != bg2.num) return bg1.num > bg2.num;
    if(bg1.y != bg2.y) return bg1.y > bg2.y;
    return bg1.x > bg2.x;
}

void bfs(int y, int x, int val){
    // cout << "bfsStart------\n";
    bool tempcheck[21][21];
    memset(tempcheck, 0, sizeof(tempcheck));

    tempcheck[y][x] = true;
    queue<pair<int,int> > q;
    q.push(make_pair(y, x));
    int cnt = 0, num = 0;

    while(!q.empty()){
        y = q.front().first, x = q.front().second;
        // cout << y << ' ' << x << '\n';
        q.pop();
        cnt++;
        for(int i=0; i<4; i++){
            int nx = x+dir[i][0], ny = y+dir[i][1];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(tempcheck[ny][nx])continue;
            if(blocks[ny][nx]==0 || blocks[ny][nx] == val){
                tempcheck[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(tempcheck[i][j]){
                if(blocks[i][j] == 0) num++;
                else{
                    check[i][j] = true;
                }
            }
            b1.tempcheck[i][j] = tempcheck[i][j];
        }
    }

    b1.num = num; b1.size = cnt;
}

void deleteBlock(){
    // 블록 그룹의 첫번째를 삭제해줌, 점수 메겨줌
    res += b.size * b.size;

    // 빈 칸을 -2로 바꿔줌
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(b.tempcheck[i][j]){
                blocks[i][j] = -2;
            }
        }
    }
}

void gravity(){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            // rot 방향대로 이동
            if(blocks[i][j]<=m && blocks[i][j]>=0){
                int x = j, y = i;
                int nx = j+dir[rot][0], ny = i+dir[rot][1];
                while(1){
                    if(nx<0||ny<0||nx>=n||ny>=n) break;
                    if(blocks[ny][nx] != -2) break;
                    int temp = blocks[y][x];
                    blocks[y][x] = -2;
                    blocks[ny][nx] = temp;
                    y = ny, x = nx;
                    ny = y+dir[rot][1], nx = x+dir[rot][0];
                }
            }
        }
    }
}

void rotate(){
    int tempBoard[21][21];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tempBoard[n-1-i][j] = blocks[j][i];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            blocks[i][j] = tempBoard[i][j];
        }
    }
}

void printBoard(){
    cout <<"------------\n";
    cout << res << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(blocks[i][j] == -2) cout << "빈 ";
            else if(blocks[i][j] == -1) cout <<"벽 ";
            else cout << blocks[i][j] << ' ';
        }
        cout <<'\n';
    }
}

int main(void){
    cin >> n >> m;
    memset(blocks, 0x3f, sizeof(blocks));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> blocks[i][j];
    while(1){
        // 체크 초기화, 블록그룹 벡터 초기화
        memset(check, 0, sizeof(check));
        b.size = 0;
        // 1. 삭제할 블록그룹 찾기
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // 번호 매겨진 애들
                if(1 <= blocks[i][j] && m >= blocks[i][j] && !check[i][j]){
                    // cout << i << ' ' << j << '\n';
                    b1.x = j, b1.y = i, b1.val = blocks[i][j];
                    memset(b1.tempcheck, 0, sizeof(b1.tempcheck));
                    bfs(i, j, blocks[i][j]);
                    if(compare(b1,b))b=b1;
                }
            }
        }

        if(b.size < 2) break;
        // 블록 삭제 
        deleteBlock();
        // 중력 작용
        gravity();
        // 방향 바꾸기
        rotate();
        // 중력 작용
        gravity();
    }

    cout << res<<'\n';
    return 0;
}