#include <iostream>
using namespace std;
#define MIN(A,B) ((A)<(B))?(A):(B)

int n, cost[1001][3];
int dp[1001][3];

int min(int a, int b, int c){
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    return c;
}

int main(void){
    cin >> n;    
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> cost[i][j];
        }
    }

    for(int i=2; i<=n; i++){
        cost[i][0] += MIN(cost[i-1][1],cost[i-1][2]);
        cost[i][1] += MIN(cost[i-1][0],cost[i-1][2]);
        cost[i][2] += MIN(cost[i-1][1],cost[i-1][0]);
    }
    cout << min(cost[n][0],cost[n][1],cost[n][2]) << '\n';
    return 0;
}