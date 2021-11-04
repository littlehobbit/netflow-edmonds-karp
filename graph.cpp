#include "graph.h"
#include "flow_graph.h"

graph::graph(const adjacency_matrix &matrix)
    : _matrix(matrix)
{}

int graph::max_flow(int from, int to) const
{
    flow_graph flow(*this, from - 1, to - 1);

    // while flow.search correct do
    // find min residual
    // correct trace's residuals
    while (flow.consist_flow()) {
        int value = flow.get_min_flow_value();
        flow.correct_flow_by_value(value);
    }


    // calc flow of start vertex
    return flow.calc_flow();
}

const graph::adjacency_matrix& graph::get_adjacency_matrix() const
{
    return _matrix;
}

size_t graph::size() const
{
    return _matrix.size();
}
