#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii; // (dist, node)

class Graph {
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt){
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u}); // undirected
    }

    void dijkstra(int src){
        vector<int> dist(V, 1e9);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();

            for(auto &edge : adj[node]){
                int wt = edge.first;
                int v = edge.second;

                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from " << src << ":\n";
        for(int i=0;i<V;i++)
            cout << "Node " << i << " : " << dist[i] << "\n";
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,10);
    g.addEdge(0,4,3);
    g.addEdge(1,2,2);
    g.addEdge(4,1,1);
    g.addEdge(4,2,8);
    g.addEdge(2,3,7);
    g.addEdge(3,4,2);

    g.dijkstra(0);
}
