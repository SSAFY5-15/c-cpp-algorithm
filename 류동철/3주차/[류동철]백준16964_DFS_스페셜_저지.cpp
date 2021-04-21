#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans[100001], order;
bool check[100001];
vector<int> v[100001];

void dfs(int s){
    if(ans[s] != order++){
        cout << 0 << '\n';
        exit(0);
    }
    check[s] = true;

    for(auto i: v[s]){
        if(check[i]) continue;
        dfs(i);
    }
}

void print(){
    for(int i=1; i<=n; i++){
        for(auto j: v[i]) cout << j << ' ';
        cout << '\n';
    }

    for(int i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

bool compare(int a, int b){
    return ans[a] < ans[b];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int s, e; cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    for(int i=0; i<n; i++){
        int t; cin >> t;
        ans[t] = i;
    }

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end(), compare);
    }

    dfs(1);
    cout << 1 << '\n';
    // print();
    return 0;
}