#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int res[6][3];
bool ans[4];

void solve(int T, int p, int q){
    if(p == 6){
        ans[T] = true;
        return;
    }
    if(q == 6) return solve(T, p+1, p+2);

    res[p][0]--;	res[q][2]--;
    if (res[p][0] >= 0 && res[q][2] >= 0) solve(T, p, q + 1);
    res[p][0]++;	res[q][2]++;
    res[p][1]--;	res[q][1]--;
    if (res[p][1] >= 0 && res[q][1] >= 0) solve(T, p, q + 1);
    res[p][1]++;	res[q][1]++;
    res[p][2]--;	res[q][0]--;
    if (res[p][2] >= 0 && res[q][0] >= 0)	solve(T, p, q + 1);
    res[p][2]++;	res[q][0]++;
}

int main(void){
    for(int tc=0; tc<4; tc++){
        int n = 0;
        for(int i=0; i<6; i++){
            for(int j=0; j<3; j++){
                scanf("%1d", &res[i][j]);
                n += res[i][j];
            }
        }

        if (n!=30) {
            ans[tc]=false;
            continue;
        }

        bool fin = true;

        for(int i=0; i<6; i++){
            if(res[i][0]+res[i][1]+res[i][2] != 5){
                fin = false;
                break;
            }
        }
        if(!fin){
            ans[tc]=false;
            continue;
        }

        solve(tc,0,1);
    }

    for(int i=0; i<4; i++){
        if(ans[i])printf("1 ");
        else printf("0 ");
    }
    return 0;
}