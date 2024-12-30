#include <bits/stdc++.h>
using namespace std;

vector<int>* adj;
int node,edge;

void IpEdgeVertices() {
    cout << "enter the no of nodes : " ;
    cin >> node;
    cout << "enter the no of edges : " ;
    cin >> edge;
}

void CreateGraphMatrix() {
    IpEdgeVertices();
    // allocate memory for 2d array
    int** matrix = new int*[node+1];
    for (int i = 0; i <=node; i++) {
        matrix[i] = new int[node+1]();
    }

    // int matrix[node+1][node+1] = {0};
    for(int i =0;i<edge;i++) {
        cout << "Enter the edge (N V): ";
        int N, V;
        cin >> N >> V;
        matrix[N][V] = 1;
        matrix[V][N] = 1;
    }
    // if node starts with 0 then i=0& i<node,j=0& j <edge
    // if node starts with 1 then i=1& i<=node,j=1& j<=edge
    for(int i = 0;i<node;i++) {
        for(int j = 0;j<=edge;j++) {
            cout  << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i <= node; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;


}
void CreateGraphList() {
    IpEdgeVertices();
    adj = new vector<int>[node+1];
    for (int i = 0; i < edge; i++) {
        cout << "Enter the edge (u v): ";
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=node;i++) {
        cout << "Node " << i << "--> ";
        for(auto j:adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    delete[] adj;
}
void printGraphMatrix(int mat[][5]) {
    for(int i = 1;i<=4;i++) {
        for(int j = 1;j<=4;j++) {
            cout  << mat[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {
    //adjacency matrix
    // int mat[5][5] = {0};
    // mat[1][2] = 1;
    // mat[1][3] = 1;
    // mat[1][4] = 1;
    // mat[2][1] = 1;
    // mat[2][3] = 1;
    // mat[3][1] = 1;
    // mat[3][2] = 1;
    // mat[4][1] = 1;
    // for(int i = 0; i < 4; i++) {
    //     int j,k;
    //     cout << "j and k  : ";
    //     cin >> j >> k;
    //     CreateGraphMatrix(mat,j,k);
    // }
    // printGraphMatrix(mat);

    // adjacency list
    CreateGraphMatrix();
    // CreateGraphList();
    return 0;
}
