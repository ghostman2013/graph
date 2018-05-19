#ifndef SET_GRAPH_HPP
#define SET_GRAPH_HPP

#include "graph.hpp"
#include <memory>
#include <unordered_map>

class set_graph : public graph {
public:
    using adj_array = std::unordered_map<vertex, vertex>[];
    using adj_array_ptr = std::unique_ptr<adj_array>;
    set_graph(const size_t size);
    set_graph(const i_graph &other);
    set_graph(set_graph &&) = default;
    ~set_graph() = default;
    set_graph &operator =(const set_graph &) = delete;
    set_graph &operator =(set_graph &&) = default;
    virtual void add_edge(const vertex from, const vertex to) override;
    virtual void next_vertices(const vertex v, vertices &vs) const override;
    virtual void prev_vertices(const vertex v, vertices &vs) const override;
private:
    adj_array_ptr m_arr;
};

#endif // SET_GRAPH_HPP
