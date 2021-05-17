#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1e9

int n, d, c;
vector<vector<pair<int, int> > > graph;
int dist[10001];

struct comp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void print();

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
    dist[c] = 0;
    pq.push(make_pair(c, 0));
    int s, v;
    int ret=0, cnt=0;

    while(!pq.empty()){
        s = pq.top().first, v = pq.top().second;
        pq.pop();
        if(dist[s] < v) continue;
        ++cnt;
        ret = v;
        // cout << s << ' '<< v << '\n';
        for(auto node : graph[s]){
            int next = node.first, val = node.second;
            if(dist[next] > dist[s]+val){
                dist[next] = dist[s]+val;
                pq.push(make_pair(next, dist[next]));
            }
        }
    }
    
    cout << cnt << ' ' << ret <<'\n';
}

void print(){
    for(int i=1; i<=n; i++){
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC; cin >> TC;

    while(TC--){
        memset(dist, 0x3f, sizeof(dist));
        graph.clear();
        cin >> n >> d >> c;
        graph.resize(n+1);

        for(int i=0; i<d; i++){
            int s, e, v; cin >> s >> e >> v;
            graph[e].push_back(make_pair(s,v));
        }

        dijkstra();
    }
    return 0;
}