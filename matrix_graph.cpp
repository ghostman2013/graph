#include "matrix_graph.hpp"
#include <algorithm>

matrix_graph::matrix_graph(const size_t size)
    : graph(size), m_mtx{std::make_unique<bool[]>(size * size)} {
    std::fill_n(m_mtx.get(), size * size, false);
}

matrix_graph::matrix_graph(const i_graph &other)
    : matrix_graph(other.vertices_count()) {
    copy(other);
}

void matrix_graph::add_edge(const vertex from, const vertex to) {
    auto size = vertices_count();
    m_mtx[size * from + to] = true;
    m_mtx[size * to + from] = true;
}

void matrix_graph::next_vertices(const vertex v, vertices &vs) const {
    auto size = vertices_count();
    for (unsigned i = 0; i < size; ++i) {
        bool is_edge = m_mtx[size * v + i];
        if (is_edge) { vs.push_back(i); }
    }
}

void matrix_graph::prev_vertices(const vertex v, vertices &vs) const {
    auto size = vertices_count();
    for (unsigned i = 0; i < size; ++i) {
        bool is_edge = m_mtx[size * i + v];
        if (is_edge) { vs.push_back(i); }
    }
}
