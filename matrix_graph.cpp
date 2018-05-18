#include "matrix_graph.hpp"
#include <algorithm>

matrix_graph::matrix_graph(const size_t size)
    : i_graph(size), m_mtx{std::make_unique<bool[]>(size * size)} {
    std::fill_n(m_mtx.get(), size * size, false);
}

matrix_graph::matrix_graph(const i_graph &graph) : i_graph(graph) {

}

void matrix_graph::add_edge(const unsigned from, const unsigned to) {
    auto size = vertices_count();
    m_mtx[size * from + to] = true;
    m_mtx[size * to + from] = true;
}

void matrix_graph::next_vertices(const int vertex, vertices &vs) const {
    auto size = vertices_count();
    for (unsigned i = 0; i < size; ++i) {
        bool is_edge = m_mtx[size * vertex + i];
        if (is_edge) { vs.push_back(i); }
    }
}

void matrix_graph::prev_vertices(const int vertex, vertices &vs) const {
    auto size = vertices_count();
    for (unsigned i = 0; i < size; ++i) {
        bool is_edge = m_mtx[size * i + vertex];
        if (is_edge) { vs.push_back(i); }
    }
}
