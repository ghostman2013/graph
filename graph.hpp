#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "i_graph.hpp"

class graph : public i_graph {
public:
    graph(const size_t size);
    virtual ~graph() = default;
    virtual void add_edge(const vertex from, const vertex to);
    virtual const size_t vertices_count() const override;
protected:
    copy(const i_graph &other);
private:
    const size_t m_size;
};

#endif // GRAPH_HPP
