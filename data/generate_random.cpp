#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace boost;
using namespace std;

int main() {
    vector<int> ns = {50, 100, 200};
    double p = 0.5;

    typedef adjacency_list<vecS, vecS, undirectedS> Graph;
    typedef erdos_renyi_iterator<mt19937, Graph> ERGen;

    mt19937 gen(time(0)); // RNG seed

    for (int n : ns) {
        Graph g(ERGen(gen, n, p), ERGen(), n);

        string filename = "random_n" + to_string(n) + ".txt";
        ofstream out(filename);
        out << num_vertices(g) << " " << num_edges(g) << "\n";
        for (auto e : make_iterator_range(edges(g))) {
            out << source(e, g) + 1 << " " << target(e, g) + 1
                << "\n"; // 1-based indexing
        }

        cout << "Generated: " << filename << endl;
    }

    return 0;
}
