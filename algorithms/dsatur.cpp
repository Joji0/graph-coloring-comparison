#include <iostream>
#include <set>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

bool uncolored(const vector<int> &color, int n) {
    for (int v = 1; v <= n; ++v)
        if (color[v] == 0)
            return true;
    return false;
}

int satDeg(int v, const Graph &G, const vector<int> &color) {
    set<int> s;
    for (int u : G[v])
        if (color[u] != 0)
            s.insert(color[u]);
    return (int)s.size();
}

int pick(const vector<int> &color, const vector<int> &sat,
         const vector<int> &deg, int n) {
    int u = -1;
    for (int v = 1; v <= n; ++v) {
        if (color[v] != 0)
            continue;
        if (u == -1 || sat[v] > sat[u] || (sat[v] == sat[u] && deg[v] > deg[u]))
            u = v;
    }
    return u;
}

int firstFit(int v, const Graph &G, const vector<int> &color) {
    set<int> used;
    for (int u : G[v])
        if (color[u] != 0)
            used.insert(color[u]);

    int c = 1;
    while (used.count(c))
        ++c;
    return c;
}

vector<int> dsaturColoring(const Graph &G, int n) {
    vector<int> color(n + 1, 0);
    vector<int> sat(n + 1, 0);
    vector<int> deg(n + 1, 0);

    for (int v = 1; v <= n; ++v)
        deg[v] = G[v].size();

    while (uncolored(color, n)) {
        int v = pick(color, sat, deg, n);
        color[v] = firstFit(v, G, color);

        for (int u : G[v])
            if (color[u] == 0)
                sat[u] = satDeg(u, G, color);
    }

    return color;
}
