#include "boost/boost/graph/adjacency_list.hpp"
#include "boost/boost/graph/erdos_renyi_generator.hpp"
#include "boost/boost/random/mersenne_twister.hpp"
#include "boost/boost/range/iterator_range.hpp"

#include <fstream>
#include <iostream>

using namespace boost;
using namespace std;

int main() {
    for (int n : {5, 25, 100}) {
        double p = 0.2;
        mt19937 gen(time(0));

        typedef adjacency_list<vecS, vecS, undirectedS> Graph;
        typedef erdos_renyi_iterator<mt19937, Graph> ERGen;

        Graph g(ERGen(gen, n, p), ERGen(), n);

        string filename = "random_n" + to_string(n) + ".txt";
        ofstream out(filename);

        out << num_vertices(g) << " " << num_edges(g) << "\n";
        for (auto e : make_iterator_range(edges(g))) {
            out << source(e, g) + 1 << " " << target(e, g) + 1 << "\n";
        }

        cout << "✅ Generated " << filename << "\n";
    }
}
