#include "i_graph.hpp"

i_graph::i_graph(const size_t size) : m_size{size} {

}

i_graph::i_graph(const i_graph &other) : m_size{other.vertices_count()} {
    for (size_t v = 0; v < m_size; ++v) {
        vertices next_vs;
        other.next_vertices(v, next_vs);
        for (auto it = next_vs.begin(); it != next_vs.end(); ++it) {
            add_edge(v, *it);
        }
    }
}

void i_graph::add_edge(const unsigned from, const unsigned to) {

}

const size_t i_graph::vertices_count() const {
    return m_size;
}
