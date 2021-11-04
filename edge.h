#ifndef EDGE_H
#define EDGE_H


struct flow_edge
{
    flow_edge() = default;

    flow_edge(int capacity, int flow, int residual)
        : capacity(capacity), flow(flow), residual(residual)
    {}

    bool is_valid()
    {
        return residual > 0;
    }

    int capacity = -1;
    int flow = -1;
    int residual = -1;
};

struct graph_edge
{
    int from;
    int to;
    int value;
};

#endif // EDGE_H
