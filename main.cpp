#include "arc_graph.hpp"
#include "list_graph.hpp"
#include "matrix_graph.hpp"
#include "set_graph.hpp"
#include <iostream>

int main() {
    arc_graph g(5);
    g.add_edge(0, 3);
    g.add_edge(0, 4);
    g.add_edge(3, 4);
    matrix_graph g2(g);
    vertices vs;
    g2.next_vertices(0, vs);
    std::cout << g2.vertices_count() << std::endl;
    vs.clear();
    g2.prev_vertices(4, vs);

    return 0;
}
