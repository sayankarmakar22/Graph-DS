#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstraAlgo(int src,int V,vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V,INT_MAX);

    distTo[src] = 0;
    pq.push({0,src});

    while(!pq.empty()) {
        int vert = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for(auto it:adj[vert]) {
            int node = it[0];
            int wt = it[1];
            if(dist + wt < distTo[node]) {
                distTo[node] = dist + wt;
                pq.push({dist+wt,node});
            }
        }
    }
    return distTo;
}

int main() {
    int V = 3, E = 3, S = 1;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> ans = dijkstraAlgo(S,V,adj);
    for(int i =0;i<V;i++) {
        cout << S << "-->" << i << " = " << ans[i] << endl;
    }
    return 0;
}
