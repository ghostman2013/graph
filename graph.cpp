#include "graph.hpp"

graph::graph(const size_t size) : m_size{size} {

}

graph::copy(const i_graph &other) {
    for (size_t v = 0; v < m_size; ++v) {
        vertices next_vs;
        other.next_vertices(v, next_vs);
        for (auto it = next_vs.begin(); it != next_vs.end(); ++it) {
            add_edge(v, *it);
        }
    }
}

void graph::add_edge(const vertex from, const vertex to) {

}

const size_t graph::vertices_count() const {
    return m_size;
}
