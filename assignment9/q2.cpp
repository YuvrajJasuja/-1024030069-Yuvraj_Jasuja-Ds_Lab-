#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int node, vector<bool>& visited){
        visited[node] = true;
        cout << node << " ";

        for(int x : adj[node])
            if(!visited[x])
                DFSUtil(x, visited);
    }

    void DFS(int start){
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout << "DFS: ";
    g.DFS(0);
}
