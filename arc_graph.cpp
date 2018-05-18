#include "arc_graph.hpp"

arc_graph::arc_graph(const size_t size) : i_graph(size) {

}

arc_graph::arc_graph(const i_graph &graph) : i_graph(graph) {

}

void arc_graph::add_edge(const unsigned from, const unsigned to) {
    for (auto it = m_edges.begin(); it != m_edges.end(); ++it) {
        if (from == it->first && to == it->second) { return; }
    }
    m_edges.push_back(edge(from, to));
}

void arc_graph::next_vertices(const int vertex, vertices &vs) const {
    for (auto it = m_edges.begin(); it != m_edges.end(); ++it) {
        if (it->first == vertex) {
            vs.push_back(it->second);
        }
    }
}

void arc_graph::prev_vertices(const int vertex, vertices &vs) const {
    for (auto it = m_edges.begin(); it != m_edges.end(); ++it) {
        if (it->second == vertex) {
            vs.push_back(it->first);
        }
    }
}
