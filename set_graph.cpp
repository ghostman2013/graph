#include "set_graph.hpp"

set_graph::set_graph(const size_t size)
    : graph(size), m_arr{std::make_unique<adj_array>(size)} {

}

set_graph::set_graph(const i_graph &other) : set_graph(other.vertices_count()) {

}

void set_graph::add_edge(const vertex from, const vertex to) {

}

void set_graph::next_vertices(const vertex v, vertices &vs) const {

}

void set_graph::prev_vertices(const vertex v, vertices &vs) const {

}
