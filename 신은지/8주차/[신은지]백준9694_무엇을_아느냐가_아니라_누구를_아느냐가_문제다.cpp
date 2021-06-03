//
//  9694.cpp
//  Week 7
//
//  Created by Eunjee Shin on 2021/05/23.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define INF 10000

vector<pair<int, int> > edge[20];
int dist[20];
int parent[20];
bool check[20];
int n, m;
int res;

void get_parent(int a){
    if (a != 0) get_parent(parent[a]);
    cout << ' ' << a;
}

void dk(){
    priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    for(int i=0; i<edge[0].size(); i++){
        pq.push(edge[0][i]);
        parent[edge[0][i].second] = 0;
        dist[edge[0][i].second] = edge[0][i].first;
    }
    check[0] = true;
    while(!pq.empty()){
        int wei = pq.top().first;
        int next = pq.top().second;
        pq.pop();
        for(int j=0; j<edge[next].size(); j++){
            int ww = edge[next][j].first;
            int nn = edge[next][j].second;
            if (!check[nn]) pq.push(edge[next][j]);
            if (dist[nn] > dist[next] + ww){
                parent[nn] = next;
                dist[nn] = dist[next] + ww;
            }
        }
        check[next] = true;
    }
    if (dist[m-1] != INF) res = dist[m-1];
}

int main(){
    int tc;
    cin >> tc;
    for(int i = 1; i<=tc; i++){
        cin >> n >> m;
        memset(dist, 0, sizeof(dist));
        memset(parent, 0, sizeof(parent));
        memset(check, false, sizeof(check));
        fill(dist+1, dist+m, INF);
        for(int j=0; j<m; j++){
            edge[j].clear();
        }
        res = -1;
        for (int j=0; j<n; j++){
            int a, b, w;
            cin >> a >> b >> w;
            edge[a].push_back(make_pair(w,b));
            edge[b].push_back(make_pair(w,a));
        }
        dk();
        cout << "Case #" << i << ":";
        if (res == -1) cout << ' ' << res;
        else get_parent(m-1);
        cout << '\n';
    }
    return 0;
}
