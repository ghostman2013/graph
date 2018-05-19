#ifndef ARC_GRAPH_HPP
#define ARC_GRAPH_HPP

#include "graph.hpp"
#include <utility>

using edge = std::pair<vertex, vertex>;
using edges = std::vector<edge>;

class arc_graph : public graph {
public:
    arc_graph(const size_t m_size);
    arc_graph(const i_graph &other);
    arc_graph(arc_graph &&) = default;
    ~arc_graph() = default;
    arc_graph &operator =(const arc_graph &) = delete;
    arc_graph &operator =(arc_graph &&) = default;
    virtual void add_edge(const vertex from, const vertex to) override;
    virtual void next_vertices(const vertex v, vertices &vs) const override;
    virtual void prev_vertices(const vertex v, vertices &vs) const override;
private:
    edges m_edges;
};

#endif // ARC_GRAPH_HPP
