#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    for (int n : {5, 25, 100}) {
        int totalVertices = n * n;
        int totalEdges = 2 * n * (n - 1);
        string filename = "grid_n" + to_string(n) + ".txt";
        ofstream out(filename);

        out << totalVertices << " " << totalEdges << "\n";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int u = i * n + j + 1;
                if (j + 1 < n) {
                    int v = i * n + (j + 1) + 1;
                    out << u << " " << v << "\n";
                }
                if (i + 1 < n) {
                    int v = (i + 1) * n + j + 1;
                    out << u << " " << v << "\n";
                }
            }
        }

        out.close();
        cout << "✅ Generated " << filename << "\n";
    }

    return 0;
}
