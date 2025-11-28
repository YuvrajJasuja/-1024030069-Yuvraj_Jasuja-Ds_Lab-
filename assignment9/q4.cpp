#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;  // (weight, node)

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
        adj[v].push_back({wt, u});
    }

    void prim(int start){
        vector<bool> inMST(V, false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, start});
        int totalCost = 0;

        while(!pq.empty()){
            auto [wt, node] = pq.top(); pq.pop();

            if(inMST[node]) continue;
            inMST[node] = true;
            totalCost += wt;

            for(auto &next : adj[node]){
                int w = next.first;
                int v = next.second;
                if(!inMST[v]) pq.push({w, v});
            }
        }

        cout << "Total MST Cost (Prim): " << totalCost;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);
    g.addEdge(3,4,9);

    g.prim(0);
}
