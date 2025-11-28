#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(rank[a] < rank[b]) swap(a,b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
    }
};

int main(){
    int V = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.wt < b.wt;
    });

    DSU dsu(V);
    vector<Edge> mst;
    int totalCost = 0;

    for(auto &e : edges){
        if(dsu.find(e.u) != dsu.find(e.v)){
            dsu.unite(e.u, e.v);
            mst.push_back(e);
            totalCost += e.wt;
        }
    }

    cout << "Kruskal MST edges:\n";
    for(auto e : mst)
        cout << e.u << " - " << e.v << " : " << e.wt << "\n";

    cout << "Total Cost: " << totalCost;
}
