#ifndef I_GRAPH_HPP
#define I_GRAPH_HPP

#include <vector>

using vertex = unsigned;
using vertices = std::vector<vertex>;

struct i_graph {
    virtual ~i_graph() = default;
    virtual void add_edge(const vertex from, const vertex to) = 0;
    virtual const size_t vertices_count() const = 0;
    virtual void next_vertices(const vertex v, vertices &vs) const = 0;
    virtual void prev_vertices(const vertex v, vertices &vs) const = 0;
};

#endif // I_GRAPH_HPP
