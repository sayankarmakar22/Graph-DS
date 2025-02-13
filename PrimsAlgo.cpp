#include <bits/stdc++.h>
using namespace std;

int primsAlgo(int V,vector<vector<int>> adj[]) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> vistied(V,0);
    pq.push({0,0});
    int cost = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if(vistied[node] == 1) continue;

        vistied[node] = 1;
        cost+= wt;

        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edW = it[1];
            if(!vistied[adjNode]) pq.push({edW,adjNode});
        }
    }
    return cost;
}

int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    cout << primsAlgo(V,adj);
    return 0;
}
