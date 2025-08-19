#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rank_;

// Initialize DSU
void makeSet(int n) {
    parent.resize(n);
    rank_.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // each node is its own parent
    }
}

// Find with path compression
int findParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node]); // path compression
}

// Union by rank
void unionSet(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if (u == v) return;  // already in same set

    if (rank_[u] < rank_[v]) {
        parent[u] = v;
    } else if (rank_[v] < rank_[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank_[u]++;
    }
}

int main() {
    int n = 7;  // number of elements (0..6)
    makeSet(n);

    // Example unions
    unionSet(0, 1);
    unionSet(1, 2);
    unionSet(3, 4);
    unionSet(5, 6);
    unionSet(4, 5);

    // Check connected components
    cout << "Parent of 2: " << findParent(2) << endl;
    cout << "Parent of 6: " << findParent(6) << endl;
    cout << "Are 2 and 6 connected? " 
         << (findParent(2) == findParent(6) ? "Yes" : "No") << endl;

    unionSet(2, 6); // now connect both components
    cout << "After union of 2 and 6:" << endl;
    cout << "Are 2 and 6 connected? " 
         << (findParent(2) == findParent(6) ? "Yes" : "No") << endl;

    return 0;
}
