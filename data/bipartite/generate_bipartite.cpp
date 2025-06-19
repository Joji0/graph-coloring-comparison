#include <fstream>
#include <iostream>
#include <random>
#include <string>

using namespace std;

const double EDGE_PROBABILITY = 0.2;

int main() {
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution edgeDist(EDGE_PROBABILITY);

    for (int n : {5, 25, 100}) {
        int partitionSize = n;
        int totalVertices = 2 * partitionSize;
        vector<pair<int, int>> edges;

        for (int u = 1; u <= partitionSize; ++u) {
            for (int v = partitionSize + 1; v <= 2 * partitionSize; ++v) {
                if (edgeDist(gen)) {
                    edges.emplace_back(u, v);
                }
            }
        }

        string filename = "bipartite_n" + to_string(n) + ".txt";
        ofstream out(filename);

        out << totalVertices << " " << edges.size() << "\n";
        for (auto &[u, v] : edges) {
            out << u << " " << v << "\n";
        }

        out.close();
        cout << "✅ Generated " << filename << " with " << edges.size()
             << " edges\n";
    }

    return 0;
}
