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
void BFS() {
    int* visited = new int[node]();
    visited[0] = 1;
    queue<int> q;
    vector<int> bfs;
    q.push(0);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node]) {
            if(!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    cout << "BFS --> { ";
    for(auto it:bfs) {
        cout << it << " ";
    }
    cout <<"}" << endl;

    delete[] visited;

}


int main() {
    CreateGraphList();
    BFS();
    delete[] adj;
    return 0;
}
