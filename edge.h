#ifndef EDGE_H
#define EDGE_H


struct flow_edge
{
    flow_edge() = default;

    flow_edge(int from, int to, int capacity, int flow, int residual)
        : from(from), to(to), capacity(capacity), flow(flow), residual(residual)
    {}

    bool is_valid()
    {
        return residual > 0;
    }

    int to;
    int from;
    flow_edge *residual_edge;

    int capacity = 0;
    int flow = 0;
    int residual = 0;
};

struct graph_edge
{
    int from;
    int to;
    int capacity;
};

#endif // EDGE_H
