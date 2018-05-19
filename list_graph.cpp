#include "list_graph.hpp"

list_graph::list_graph(const size_t size)
    : graph(size), m_arr{std::make_unique<vertices[]>(size)} {
    for (vertex i = 0; i < size; ++i) {
        m_arr[i] = vertices();
        m_arr[i].reserve(size);
    }
}

list_graph::list_graph(const i_graph &other) : graph(other) {

}

void list_graph::add_edge(const vertex from, const vertex to) {
    auto &adj_vs = m_arr[from];
    if (std::find(adj_vs.begin(), adj_vs.end(), to) == adj_vs.end()) {
        adj_vs.push_back(to);
    }
}

void list_graph::next_vertices(const vertex v, vertices &vs) const {
    auto &adj_vs = m_arr[v];
    vs.insert(vs.end(), adj_vs.begin(), adj_vs.end());
}

void list_graph::prev_vertices(const vertex v, vertices &vs) const {
    for (vertex i = 0; i < vertices_count(); ++i) {
        auto &adj_vs = m_arr[i];
        if (std::find(adj_vs.begin(), adj_vs.end(), v) != adj_vs.end()) {
            vs.push_back(i);
        }
    }
}
