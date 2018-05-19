#ifndef LIST_GRAPH_HPP
#define LIST_GRAPH_HPP

#include "graph.hpp"
#include <algorithm>
#include <memory>
#include <vector>

class list_graph : public graph {
public:
    using adj_array = std::unique_ptr<vertices[]>;

    list_graph(const size_t size);
    list_graph(const i_graph &other);
    list_graph(list_graph &&) = default;
    ~list_graph() = default;

    list_graph &operator =(const list_graph &) = delete;
    list_graph &operator =(list_graph &&) = default;
    virtual void add_edge(const vertex from, const vertex to) override;
    virtual void next_vertices(const vertex v, vertices &vs) const override;
    virtual void prev_vertices(const vertex v, vertices &vs) const override;
private:
    adj_array m_arr;
};

#endif // LIST_GRAPH_HPP
