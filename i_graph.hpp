#ifndef I_GRAPH_HPP
#define I_GRAPH_HPP

#include <vector>

using vertices = std::vector<int>;

struct i_graph {
    i_graph(const size_t m_size);
    i_graph(const i_graph &other);
    virtual ~i_graph() = default;
    virtual void add_edge(const unsigned from, const unsigned to);
    const size_t vertices_count() const;
    virtual void next_vertices(const int vertex, vertices &vs) const = 0;
    virtual void prev_vertices(const int vertex, vertices &vs) const = 0;
private:
    const size_t m_size;
};

#endif // I_GRAPH_HPP
