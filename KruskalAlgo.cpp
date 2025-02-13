#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

void make(int v) {
    parent[v] = v;
}
int find(int v) {
     if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b)
        parent[a] = b;
}

void kruskalAlgo(vector<pair<int,pair<int,int>>> edges,int vert) {
    //sort the edges and pick the smallest one
    sort(edges.begin(), edges.end());

    parent.resize(vert);
    for (int i = 0; i < vert; i++)
        make(i);

    int total_cost = 0;
    for(auto &edge : edges) {
        int weight = edge.first;
        int u  = edge.second.first;
        int v  = edge.second.second;


        //If both nodes have the same root, we don't include them because it would create a loop.
        if(find(u) == find(v)) continue;

        //if not then merge them using Union() function
        Union(u, v);
        //add that weight
        total_cost += weight;

    }
    cout <<"Min Spanning Tree Cost : " <<total_cost << endl;
}

int main() {
    vector<pair<int,pair<int,int>>> v;

    //creating the graph
    v.push_back(make_pair(10,make_pair(0,1)));
    v.push_back(make_pair(15,make_pair(1,3)));
    v.push_back(make_pair(4,make_pair(2,3)));
    v.push_back(make_pair(6,make_pair(2,0)));
    v.push_back(make_pair(5,make_pair(0,3)));

    kruskalAlgo(v,4);
    return 0;
}
