#ifndef MATRIX_GRAPH_HPP
#define MATRIX_GRAPH_HPP

#include "graph.hpp"
#include <memory>

class matrix_graph : public graph {
public:
    matrix_graph(const size_t m_size);
    matrix_graph(const i_graph &other);
    matrix_graph(matrix_graph &&) = default;
    ~matrix_graph() = default;
    matrix_graph &operator =(const matrix_graph &other) = delete;
    matrix_graph &operator =(matrix_graph &&other) = default;
    virtual void add_edge(const vertex from, const vertex to) override;
    virtual void next_vertices(const vertex v, vertices &vs) const override;
    virtual void prev_vertices(const vertex v, vertices &vs) const override;
private:
    std::unique_ptr<bool[]> m_mtx;
};

#endif // MATRIX_GRAPH_HPP
