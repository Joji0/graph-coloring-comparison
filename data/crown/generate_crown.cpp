#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
    random_device rd;
    mt19937 rng(rd());

    for (int n : {5, 25, 100}) {
        int totalVertices = 2 * n;
        string filename = "crown_n" + to_string(n) + ".txt";

        vector<pair<int, int>> edges;
        for (int u = 1; u <= n; ++u) {
            for (int v = n + 1; v <= 2 * n; ++v) {
                if (v != u + n) {
                    edges.emplace_back(u, v);
                }
            }
        }

        vector<int> perm(totalVertices + 1);
        for (int i = 1; i <= totalVertices; ++i)
            perm[i] = i;
        shuffle(perm.begin() + 1, perm.end(), rng);

        vector<pair<int, int>> shuffledEdges;
        for (auto &[u, v] : edges) {
            shuffledEdges.emplace_back(perm[u], perm[v]);
        }

        shuffle(shuffledEdges.begin(), shuffledEdges.end(), rng);

        ofstream out(filename);
        out << totalVertices << " " << shuffledEdges.size() << "\n";
        for (auto &[u, v] : shuffledEdges) {
            out << u << " " << v << "\n";
        }

        out.close();
        cout << "✅ Generated " << filename << " with shuffled vertex labels\n";
    }

    return 0;
}
