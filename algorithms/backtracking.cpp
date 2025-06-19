#include <iostream>
#include <vector>

using namespace std;

// This implementation uses adjacency list representation
using Graph = vector<vector<int>>;

bool isSafe(int v, int c, const Graph &G, const vector<int> &color) {
    for (int u : G[v]) {
        if (color[u] == c)
            return false;
    }
    return true;
}

bool colorVertex(int v, const Graph &G, vector<int> &color, int k, int n) {
    if (v > n)
        return true;

    for (int c = 1; c <= k; ++c) {
        if (isSafe(v, c, G, color)) {
            color[v] = c;
            if (colorVertex(v + 1, G, color, k, n))
                return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

vector<int> backtrackGraphColoring(const Graph &G, int k, int n) {
    vector<int> color(n + 1, 0); // 1-based indexing

    if (colorVertex(1, G, color, k, n)) {
        return color;
    } else {
        return {}; // No valid coloring
    }
}
