#ifndef ARC_GRAPH_HPP
#define ARC_GRAPH_HPP

#include "i_graph.hpp"
#include <utility>

using edge = std::pair<unsigned, unsigned>;
using edges = std::vector<edge>;

class arc_graph : public i_graph {
public:
    arc_graph(const size_t m_size);
    arc_graph(const i_graph &graph);
    arc_graph(arc_graph &&graph) = default;
    ~arc_graph() = default;
    arc_graph &operator =(const arc_graph &other) = delete;
    arc_graph &operator =(arc_graph &&other) = default;
    virtual void add_edge(const unsigned from, const unsigned to) override;
    virtual void next_vertices(const int vertex, vertices &vs) const override;
    virtual void prev_vertices(const int vertex, vertices &vs) const override;
private:
    edges m_edges;
};

#endif // ARC_GRAPH_HPP
