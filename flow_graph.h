#ifndef FLOW_GRAPH_H
#define FLOW_GRAPH_H

#include <vector>

#include "graph.h"
#include "edge.h"

class flow_graph
{
public:
    using adjacency_matrix = std::vector<std::vector<flow_edge>>;

    flow_graph(const graph& graph, int start, int stop);

    bool consist_flow();

    int get_min_flow_value();

    void correct_flow_by_value(int value);

    int calc_flow();

private:
    // TODO: store matrix of edges;
    adjacency_matrix _matrix;
    std::vector<int> _parents;
    int _start;
    int _stop;
};

#endif // FLOW_GRAPH_H
