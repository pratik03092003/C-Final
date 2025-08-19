// C++ program for Kruskal’s MST using DSU
#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    static bool comp(vector<int>&a, vector<int>&b) {
        return a[2] < b[2];
    }

    int findparent(int node, vector<int> &parent) {
        if (parent[node] == node) return parent[node];
        return parent[node] = findparent(parent[node], parent); // path compression
    }

    void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findparent(u, parent);
        v = findparent(v, parent);
        if (u == v) return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), comp);

        vector<int> parent(V);
        for (int i = 0; i < V; i++) parent[i] = i;
        vector<int> rank(V, 0);

        int mstcost = 0;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (findparent(u, parent) != findparent(v, parent)) {
                unionset(u, v, parent, rank);
                mstcost += wt;
            }
        }
        return mstcost;
    }
};

// -------------------- MAIN FUNCTION --------------------
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter edges (u v wt):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    Solution sol;
    int mstCost = sol.kruskalsMST(V, edges);

    cout << "Cost of Minimum Spanning Tree: " << mstCost << endl;
    return 0;
}
