#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<list<int>> graph;
  
    void add_edge(int a, int b, bool bider){
        graph[a].push_back(b); 
        if(bider){
            graph[b].push_back(a);
        }
    }
  
    // Topological Sort using Kahn’s Algorithm
    vector<int> topoSort(int V){
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto neighbor : graph[i]){
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(auto neighbor : graph[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return topo;
    }

    // Shortest Path in DAG (edge weight = 1)
    vector<int> shortestPath(int V, int src){
        vector<int> dist(V, 1e9); // infinity
        dist[src] = 0;

        vector<int> topo = topoSort(V);

        for(int u : topo){
            if(dist[u] != 1e9){
                for(int v : graph[u]){
                    if(dist[u] + 1 < dist[v]){
                        dist[v] = dist[u] + 1;
                    }
                }
            }
        }
        return dist;
    }
};

int main(){
    int V = 6;
    Solution sol;
    sol.graph.resize(V);

    // Add edges (directed)
    sol.add_edge(0, 1, false);
    sol.add_edge(0, 4, false);
    sol.add_edge(4, 5, false);
    sol.add_edge(4, 2, false);
    sol.add_edge(1, 2, false);
    sol.add_edge(2, 3, false);
    sol.add_edge(5, 3, false);

    int src = 0;
    vector<int> result = sol.shortestPath(V, src);

    cout << "Shortest paths from source " << src << ":\n";
    for(int i=0; i<V; i++){
        if(result[i] == 1e9) cout << "Node " << i << " is unreachable\n";
        else cout << "Node " << i << " is at distance " << result[i] << "\n";
    }

    return 0;
}
