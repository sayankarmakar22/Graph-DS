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
void DFS(int Node,int vis[],vector<int>&dfs) {
    vis[Node] = 1;
    dfs.push_back(Node);
    for(auto j:adj[Node]) {
        if(!vis[j]) {
            DFS(j,vis,dfs);
        }
    }
}
void DfsOfGraph() {

    int* visited = new int[node]();
    int start = 0;
    vector<int> dfs;
    DFS(start,visited,dfs);

    cout<< "DFS ---> {";
    for(auto i:dfs) {
        cout << i << " ";
    }
    cout<<"}" << endl;

    delete[] visited;

}

int main() {
    //creating the graph
    CreateGraphList();

    //calling the dfs function
    DfsOfGraph();
    //deleting the adj list
    delete[] adj;

    return 0;
}
