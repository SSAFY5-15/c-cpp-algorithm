#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int n, board[21][21], ans=2100000000;
int bit = 0;

void comb(int x, int s){
    if(x == n/2){
        int start=0, link=0;
        for(int i=0; i<n; i++){
            if(bit & (1<<i)){
                for(int j=i+1; j<n; j++){
                    if (bit & (1<<j)){
                        start += board[i][j];
                        start += board[j][i];
                    }
                }
            }
            else{
                for(int j=i+1; j<n; j++){
                    if (!(bit & (1<<j))){
                        link += board[i][j];
                        link += board[j][i];
                    }
                }
            }
        }
        if(abs(start-link) < ans) ans = abs(start-link);
        

        return;
    }

    if (s >= n) return;
    
    bit |= (1 << s);
    comb(x+1, s+1);
    bit ^= (1 << s);
    comb(x, s+1);
}

int main(void){
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> board[i][j];

    comb(0, 0);
    cout << ans << '\n';

    return 0;
}