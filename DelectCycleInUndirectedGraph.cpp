#include <bits/stdc++.h>
using namespace std;

vector<int>* adj;
int node,edge;

void CreateGraphList() {
    cout << "enter the no of nodes : " ;
    cin >> node;
    cout << "enter the no of edges : " ;
    cin >> edge;
    adj = new vector<int>[node+1];
    for (int i = 0; i < edge; i++) {
        cout << "Enter the edge (u v): ";
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<node;i++) {
        cout << "Node " << i << "--> ";
        for(auto j:adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

}

bool dfs(int v, int parent, vector<int>&vis) {
    vis[v] = 1;
    for(auto neighbor:adj[v]) {
        if(!vis[neighbor]) {
            if(dfs(neighbor, v, vis)) return true;
        }
        else if(parent != neighbor) return true;
    }
    return false;
}

bool detectCycle() {
    vector<int>vis(node, false);
    for(int i =0;i<node;i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis)) return true;
        }
    }
    return false;
}

int main() {
    CreateGraphList();

    detectCycle() ? cout << "Cycle detected" : cout << "No cycle detected";

    delete[] adj;
    return 0;
}
