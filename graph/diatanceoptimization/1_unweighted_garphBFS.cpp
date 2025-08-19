#include <iostream>
#include <vector>
#include <list> // Include the <list> header
#include <queue>

using namespace std;

// Function to find shortest path from source
// Notice the change in the 'adj' parameter type
void shortestPath_BFS(int V, vector<list<int>>& adj, int src) {
    // Distance vector to store the shortest distance.
    vector<int> dist(V, 1e9);

    // Queue for BFS
    queue<int> q;

    // Source distance is 0
    dist[src] = 0;
    q.push(src);

    // Standard BFS loop
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // The range-based for loop works perfectly with std::list too!
        for (auto neighbor : adj[node]) {
            if (dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Print all the distances
    cout << "Shortest distances from source " << src << " are:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << " is at distance: " << dist[i] << endl;
    }
}

int main() {
    int V = 6;
    // **CHANGED**: Initializing a vector of lists
    vector<list<int>> adj(V);

    // Edges are added in the same way using push_back
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[3].push_back(5);
    adj[5].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);

    int sourceNode = 0;
    shortestPath_BFS(V, adj, sourceNode);

    return 0;
}