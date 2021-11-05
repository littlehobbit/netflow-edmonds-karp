#ifndef FLOW_GRAPH_H
#define FLOW_GRAPH_H

#include <vector>
#include <list>

#include "graph.h"
#include "edge.h"

class flow_graph
{
public:
    flow_graph(const graph& graph, int start, int stop);

    ~flow_graph();

    bool consist_flow();

    int get_min_flow_value();

    void correct_flow_by_value(int value);

    int calc_flow();

private:
    std::vector<std::list<flow_edge *>> _residual_graph;
    std::vector<flow_edge *> _prev;
    int _start;
    int _stop;
};

#endif // FLOW_GRAPH_H
