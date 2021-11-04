#include <queue>
#include <limits>

#include "flow_graph.h"

flow_graph::flow_graph(const graph& graph, int start, int stop)
    : _matrix(graph.size(), std::vector<flow_edge>(graph.size())),
      _parents(graph.size()),
      _start(start),
      _stop(stop)
{
    auto matrix = graph.get_adjacency_matrix();
    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = 0; j < graph.size(); j++) {
            int edge = matrix[i][j];
            if (edge != -1) {
                _matrix[i][j] = flow_edge(edge, 0, edge);
                if (_matrix[j][i].capacity == -1)
                    _matrix[j][i] = flow_edge(edge, 0, 0);
            }
        }
    }
}

bool flow_graph::consist_flow()
{
    std::queue<int> vertexes;
    vertexes.push(_start);

    std::vector<bool> visited(_matrix.size(), false);
    visited[_start] = true;

    while (!vertexes.empty()) {
        int v = vertexes.front();
        vertexes.pop();

        for (int u = 0; u < _matrix.size(); u++) {
            flow_edge &edge = _matrix[v][u];
            if (!visited[u] && edge.is_valid()) {
                vertexes.push(u);
                _parents[u] = v;
                visited[u] = true;
                if (u == _stop) return true;
            }
        }
    }

    return false;
}

int flow_graph::get_min_flow_value()
{
    int total = _stop, min_volume = std::numeric_limits<int>::max();
    while (total != _start) {
        flow_edge &edge = _matrix[_parents[total]][total];
        min_volume = std::min(min_volume, edge.residual);
        total = _parents[total];
    }
    return min_volume;
}

void flow_graph::correct_flow_by_value(int value)
{
    int total = _stop;
    while (total != _start) {
        flow_edge &edge = _matrix[_parents[total]][total];
        flow_edge &reverse_edge = _matrix[total][_parents[total]];

        edge.flow += value;
        edge.residual -= value;

        reverse_edge.residual += value;

        total = _parents[total];
    }
}

int flow_graph::calc_flow()
{
    int flow = 0;
    for (int i = 0; i < _matrix.size(); i++) {
        flow_edge &edge = _matrix[0][i];
        if (edge.flow > 0)
            flow += edge.flow;
    }
    return flow;
}
