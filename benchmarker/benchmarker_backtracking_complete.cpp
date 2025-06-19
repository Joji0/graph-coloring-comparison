#include "../algorithms/backtracking.cpp"
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;
using Graph = vector<vector<int>>;

const string DATA_DIR = "../data/complete/";
const string RESULT_DIR = "../results/";

Graph loadGraphFromFile(const string &filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "❌ Error: Graph file not found: " << filename << "\n";
        exit(1);
    }
    int n, m;
    in >> n >> m;
    Graph G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        in >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    return G;
}

int main() {
    int n;
    int64_t totalDuration = 0;
    int totalColors = 0;

    cout << "📌 Choose amount of vertices (available: 5, 25, 100): ";
    cin >> n;

    if (n != 5 && n != 25 && n != 100) {
        cerr << "❌ Invalid size. Allowed values: 5, 25, 100\n";
        return 1;
    }

    filesystem::create_directory(RESULT_DIR);

    string inputFile = DATA_DIR + "complete_n" + to_string(n) + ".txt";
    string outputFile =
        RESULT_DIR + "backtracking_complete_n" + to_string(n) + "_results.txt";

    Graph G = loadGraphFromFile(inputFile);

    ofstream out(outputFile);
    if (!out.is_open()) {
        cerr << "❌ Failed to open output file for writing: " << outputFile
             << "\n";
        return 1;
    }

    cout << "\n▶️ Running backtracking on complete graph with n = " << n
         << "...\n";

    for (int i = 1; i <= 1001; ++i) {
        int k = 1;
        vector<int> coloring;

        auto start = high_resolution_clock::now();

        while (true) {
            coloring = backtrackGraphColoring(G, k, (int)G.size() - 1);
            if (!coloring.empty())
                break;
            ++k;
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start).count();

        if (i > 1) {
            totalDuration += duration;
            totalColors += k;
        }

        out << "Iteration " << i << ": colors used = " << k
            << ", time = " << duration << " ns"
            << (i > 1 ? "\n" : " (warmup is ignored)\n");

        cout << "⏱️ Iteration " << i << ": colors used = " << k
             << ", time = " << duration << " ns"
             << (i > 1 ? "\n" : " (warmup is ignored)\n");
    }

    out << "\n--- Summary ---\n";
    out << "Average time: " << (totalDuration / 1000.0) << " ns\n";
    out << "Average colors used: " << (totalColors / 1000.0) << "\n";

    cout << "\n📊 Summary:\n";
    cout << "Average time: " << (totalDuration / 1000.0) << " ns\n";
    cout << "Average colors used: " << (totalColors / 1000.0) << "\n";

    cout << "✅ Done. Results saved to: " << outputFile << "\n";
    return 0;
}
