#include <iostream>
#include <vector>
#include <list>
#include <set> // Include the <set> header

using namespace std;

void dijkstra_set(int V, vector<list<pair<int, int>>>& adj, int src) {
    // Distance vector, initialized to infinity
    vector<int> dist(V, 1e9);

    // Set to store {distance, node}. It's naturally sorted by the first element.
    set<pair<int, int>> s;

    // Start with the source node
    dist[src] = 0;
    s.insert({0, src}); // {distance, node}

    while (!s.empty()) {
        // Get the node with the smallest distance from the beginning of the set
        auto top_element = *s.begin();//top->elemint jiska diatance kam hoga
        int u = top_element.second;//node extract kro
        s.erase(s.begin()); // Remove it from the set

        // Explore the neighbors of the current node 'u'
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // "Relaxation" step
            if (dist[u] + weight < dist[v]) {
                // If we found a shorter path, we must update the set.
                
                // 1. If 'v' was already in the set with an old distance, remove it.
                if (dist[v] != 1e9) {
                    s.erase({dist[v], v});
                }

                // 2. Update the distance in our distance array.
                dist[v] = dist[u] + weight;

                // 3. Insert the new {distance, node} pair into the set.
                s.insert({dist[v], v});
            }
        }
    }

    // Print the final shortest distances
    cout << "Shortest distances from source " << src << " (using set) are:" << endl;
    for (int i = 0; i < V; ++i) {
        if (dist[i] == 1e9) {
            cout << "Node " << i << " is not reachable." << endl;
        } else {
            cout << "Node " << i << " is at distance: " << dist[i] << endl;
        }
    }
}

int main() {
    int V = 5;
    vector<list<pair<int, int>>> adj(V);

    // Adding edges: {destination, weight}
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 1});
    adj[1].push_back({2, 4});
    adj[2].push_back({3, 3});
    adj[2].push_back({4, 1});
    adj[3].push_back({0, 1});
    adj[4].push_back({1, 5});

    int sourceNode = 0;
    dijkstra_set(V, adj, sourceNode);

    return 0;
}