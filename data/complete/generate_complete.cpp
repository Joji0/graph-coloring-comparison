#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    for (int n : {5, 25, 100}) {
        int totalVertices = n;
        int totalEdges = n * (n - 1) / 2;
        string filename = "complete_n" + to_string(n) + ".txt";
        ofstream out(filename);

        out << totalVertices << " " << totalEdges << "\n";

        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                out << u << " " << v << "\n";
            }
        }

        out.close();
        cout << "✅ Generated " << filename << "\n";
    }

    return 0;
}
