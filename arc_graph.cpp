#include "arc_graph.hpp"

arc_graph::arc_graph(const size_t size) : graph(size) {

}

arc_graph::arc_graph(const i_graph &other) : graph(other) {

}

void arc_graph::add_edge(const vertex from, const vertex to) {
    for (auto it = m_edges.begin(); it != m_edges.end(); ++it) {
        if (from == it->first && to == it->second) { return; }
    }
    m_edges.push_back(edge(from, to));
}

void arc_graph::next_vertices(const vertex v, vertices &vs) const {
    for (auto it = m_edges.begin(); it != m_edges.end(); ++it) {
        if (it->first == v) {
            vs.push_back(it->second);
        }
    }
}

void arc_graph::prev_vertices(const vertex v, vertices &vs) const {
    for (auto it = m_edges.begin(); it != m_edges.end(); ++it) {
        if (it->second == v) {
            vs.push_back(it->first);
        }
    }
}
