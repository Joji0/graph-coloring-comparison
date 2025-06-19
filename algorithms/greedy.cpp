#include <iostream>
#include <set>
#include <vector>

using namespace std;

// This implementation uses adjacency list representation
using Graph = vector<vector<int>>;

vector<int> greedyColoring(const Graph &G, int n) {
    vector<int> color(n + 1, 0); // 1-based indexing

    for (int v = 1; v <= n; ++v) {
        set<int> used;
        for (int u : G[v]) {
            if (color[u] != 0)
                used.insert(color[u]);
        }

        int c = 1;
        while (used.count(c))
            ++c;

        color[v] = c;
    }

    return color;
}
