#include <iostream>
#include <algorithm>
using namespace std;

struct edge{int s,e,val;} graph[100005];
int n, m, p[1005], r[1005];

bool cmp(edge a, edge b){return a.val < b.val;}
int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}
void uni(int x, int y){
    x = find(x), y = find(y);
    if(r[x] < r[y]) p[y] = x;
    else p[x] = y;

    if(r[x] == r[y]) r[x]++;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<=n; i++) p[i]=i;
    for(int i=0; i<m; i++) cin >> graph[i].s >> graph[i].e >> graph[i].val;
    sort(graph,graph+m,cmp);

    int ret = 0;
    for (int i=0; i<m; i++) {
        if(find(graph[i].s) == find(graph[i].e)) continue;
        uni(graph[i].s,graph[i].e);
        ret += graph[i].val;
    }

    cout << ret << '\n';

    return 0;
}