#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 2147483647
#define pii pair<int, int>
#define lli long long int

int v, e;
int d[10001];
bool check[10001];
vector<vector<pii> > graph;

struct cmp{
    bool operator()(pii a, pii b){
        return a.second > b.second;
    }
};

priority_queue<pii,vector<pii>,cmp> pq;

void addEdge(int n){
    for(auto i: graph[n]){
        pq.push(i);
    }
}

lli prim(){
    lli ret=0;
    pq.push(make_pair(1,0));
    for(int i=1; i<=v; i++){
        int cur=-1, min_dist=INF;
        while(!pq.empty()){
            cur = pq.top().first;
            if(!check[cur]){
                ret += pq.top().second;
                pq.pop();
                check[cur] = true;
                addEdge(cur);
                break;
            }
            pq.pop();
        }
    }

    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v>> e;
    graph.resize(v+1);

    for(int i=0; i<e; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    cout << prim() << '\n';

    return 0;
}